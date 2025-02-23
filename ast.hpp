#ifndef AST_NODES_HPP__
#define AST_NODES_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "symbol.hpp"

// Forward declaration of error reporting:
void yyerror(const char *msg);

// Global indentation string for printing:
extern std::string indentationSpaces;

/*
   A generic AST node, holding a line number for error-reporting.
*/
class ASTNode {
public:
    virtual ~ASTNode() {}

    void setLine(int ln) { lineNumber = ln; }
    int  getLine() const { return lineNumber; }

    virtual void printTree(std::ostream &out) const = 0;
    virtual void semanticCheck() {}

protected:
    int lineNumber = -1;
};

// Allow printing any AST node using <<:
inline std::ostream& operator<<(std::ostream &out, const ASTNode &node) {
    node.printTree(out);
    return out;
}

// Print RType values:
inline std::ostream& operator<<(std::ostream &out, const RType &t) {
    switch (t) {
        case TYPE_int:        out << "int";          break;
        case TYPE_char:       out << "char";         break;
        case TYPE_void:       out << "void";         break;
        case TYPE_string:     out << "string";       break;
        case TYPE_int_array:  out << "int array";    break;
        case TYPE_char_array: out << "char array";   break;
    }
    return out;
}

/* ----------------------------------------------------------------
   ExpressionNode base class
   ----------------------------------------------------------------*/
class ExpressionNode : public ASTNode {
public:
    virtual ~ExpressionNode() {}
    // Evaluate the expression to produce a 'variables' union:
    virtual variables evaluate() const = 0;

    // Check that the ExpressionNode matches the expected type:
    void confirmType(RType expected) {
        semanticCheck();
        if (exprDataType != expected) {
            std::ostringstream errorText;
            errorText << "Type mismatch on line " << getLine()
                      << ": expected " << expected
                      << ", got " << exprDataType;
            yyerror(errorText.str().c_str());
        }
    }

    RType getDataType() const { return exprDataType; }

protected:
    RType exprDataType;
};

/* ----------------------------------------------------------------
   A sequence of expressions (e.g., function arguments)
   ----------------------------------------------------------------*/
class ExpressionSequence : public ASTNode {
public:
    ExpressionSequence() {
        exprList = new std::vector<ExpressionNode*>();
    }
    ~ExpressionSequence() {
        // If you own these expr pointers, you might want to delete them.
        // e.g. for (auto e : *exprList) delete e;
        // delete exprList;
    }

    void addExpression(ExpressionNode* e) {
        exprList->push_back(e);
    }

    std::vector<ExpressionNode*>* getAll() {
        return exprList;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "ExpressionSequence(...)";
    }

private:
    std::vector<ExpressionNode*> *exprList;
};

/* ----------------------------------------------------------------
   Base class for statements
   ----------------------------------------------------------------*/
class StatementNode : public ASTNode {
public:
    virtual ~StatementNode() {}
    virtual void execute() const = 0;
};

/* ----------------------------------------------------------------
   Base class for conditional nodes
   ----------------------------------------------------------------*/
class ConditionNode : public ASTNode {
public:
    virtual ~ConditionNode() {}
    virtual variables evaluate() const = 0;

    void confirmType(RType expected) {
        semanticCheck();
        if (condDataType != expected) {
            std::string msg = "Condition type mismatch on line "
                              + std::to_string(getLine());
            yyerror(msg.c_str());
        }
    }

protected:
    RType condDataType;
};

/* ----------------------------------------------------------------
   LocalDefinition base class (variables or functions)
   ----------------------------------------------------------------*/
class LocalDefinition : public ASTNode {
public:
    virtual ~LocalDefinition() {}
    virtual void execute() const = 0;
};

/* ----------------------------------------------------------------
   DefinitionList: holds multiple local definitions
   ----------------------------------------------------------------*/
class DefinitionList : public ASTNode {
public:
    DefinitionList() {
        definitions = new std::vector<LocalDefinition*>();
    }
    ~DefinitionList() {
        // e.g. for (auto d : *definitions) delete d;
        // delete definitions;
    }

    void addDefinition(LocalDefinition* d) {
        definitions->push_back(d);
    }

    std::vector<LocalDefinition*>* getAll() {
        return definitions;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "DefinitionList(...)";
    }

private:
    std::vector<LocalDefinition*> *definitions;
};

/* ----------------------------------------------------------------
   Formal parameter
   ----------------------------------------------------------------*/
class FunctionParameter : public ASTNode {
public:
    FunctionParameter(std::string *nm, bool isRef, RType tp)
        : paramName(*nm), referenceFlag(isRef), paramType(tp)
    {}

    virtual void semanticCheck() override {
        symbolTable.insert(paramName, paramType);
    }

    RType getParamType() const       { return paramType; }
    std::string getName() const      { return paramName; }
    bool isReference() const         { return referenceFlag; }

    virtual void printTree(std::ostream &out) const override {
        if (referenceFlag) {
            out << "FunctionParameter(" << paramName << ", " << paramType << ", ref)";
        } else {
            out << "FunctionParameter(" << paramName << ", " << paramType << ")";
        }
    }

private:
    std::string paramName;
    bool        referenceFlag;
    RType       paramType;
};

/* ----------------------------------------------------------------
   List of formal parameters
   ----------------------------------------------------------------*/
class ParameterList : public ASTNode {
public:
    ParameterList() {
        paramList = new std::vector<FunctionParameter*>();
    }
    ~ParameterList() {
        // e.g. for (auto p : *paramList) delete p;
        // delete paramList;
    }

    void addParameter(FunctionParameter* p) {
        paramList->push_back(p);
    }

    std::vector<FunctionParameter*>* getAll() {
        return paramList;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "ParameterList(...)";
    }

private:
    std::vector<FunctionParameter*> *paramList;
};

/* ----------------------------------------------------------------
   BinaryOpExpression: e.g. expr + expr
   ----------------------------------------------------------------*/
class BinaryOpExpression : public ExpressionNode {
public:
    BinaryOpExpression(ExpressionNode* lhs, char oper, ExpressionNode* rhs)
        : left(lhs), op(oper), right(rhs) {}
    ~BinaryOpExpression() {
        delete left;
        delete right;
    }

    virtual variables evaluate() const override {
        int lv = left->evaluate().i;
        int rv = right->evaluate().i;
        variables outcome;
        switch (op) {
            case '+': outcome.i = lv + rv; break;
            case '-': outcome.i = lv - rv; break;
            case '*': outcome.i = lv * rv; break;
            case '/': outcome.i = lv / rv; break;
            case '%': outcome.i = lv % rv; break;
        }
        return outcome;
    }

    virtual void semanticCheck() override {
        left->confirmType(TYPE_int);
        right->confirmType(TYPE_int);
        exprDataType = TYPE_int;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "BinaryOpExpression(" << op << "\n";
        indentationSpaces += "  ";
        out << indentationSpaces << *left << "\n";
        out << indentationSpaces << *right << "\n";
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    ExpressionNode* left;
    char            op;
    ExpressionNode* right;
};

/* ----------------------------------------------------------------
   UnaryOpExpression: e.g. -expr
   ----------------------------------------------------------------*/
class UnaryOpExpression : public ExpressionNode {
public:
    UnaryOpExpression(char oper, ExpressionNode* e)
        : op(oper), subExpr(e) {}
    ~UnaryOpExpression() {
        delete subExpr;
    }

    virtual variables evaluate() const override {
        int val = subExpr->evaluate().i;
        variables result;
        result.i = (op == '-') ? -val : val;
        return result;
    }

    virtual void semanticCheck() override {
        subExpr->confirmType(TYPE_int);
        exprDataType = TYPE_int;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "UnaryOpExpression(" << op << "\n";
        indentationSpaces += "  ";
        out << indentationSpaces << *subExpr << "\n";
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    char            op;
    ExpressionNode* subExpr;
};

/* ----------------------------------------------------------------
   IntegerConstant: e.g. 42
   ----------------------------------------------------------------*/
class IntegerConstant : public ExpressionNode {
public:
    IntegerConstant(int n) : value(n) {}

    virtual variables evaluate() const override {
        variables v;
        v.i = value;
        return v;
    }

    virtual void semanticCheck() override {
        exprDataType = TYPE_int;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "IntegerConstant(" << value << ")";
    }

    int getValue() const { return value; }

private:
    int value;
};

/* ----------------------------------------------------------------
   CharConstant: e.g. 'a'
   ----------------------------------------------------------------*/
class CharConstant : public ExpressionNode {
public:
    CharConstant(char c) : ch(c) {}

    virtual variables evaluate() const override {
        variables v;
        v.c = ch;
        return v;
    }

    virtual void semanticCheck() override {
        exprDataType = TYPE_char;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "CharConstant(" << ch << ")";
    }

private:
    char ch;
};

/* ----------------------------------------------------------------
   LeftValue base class
   ----------------------------------------------------------------*/
class LeftValue : public ExpressionNode {
public:
    virtual ~LeftValue() {}
    virtual variables* getMemoryAddress() const = 0;
};

/* ----------------------------------------------------------------
   LeftValueID: e.g. x or x[expr]
   ----------------------------------------------------------------*/
class LeftValueID : public LeftValue {
public:
    LeftValueID(std::string *nm, ExpressionNode* idx)
        : varName(*nm), indexExpression(idx) {}
    LeftValueID(std::string *nm)
        : varName(*nm), indexExpression(nullptr) {}
    ~LeftValueID() {
        delete indexExpression;
    }

    virtual variables evaluate() const override {
        RuntimeRecord *rec = symbolTable.getTop();
        variables *theVar = nullptr;
        if (rec->locals.find(varName) != rec->locals.end())
            theVar = rec->locals[varName];
        else
            theVar = rec->arguments[varName];

        // Array indexing
        if (indexExpression) {
            auto idxVal = static_cast<size_t>(indexExpression->evaluate().i);
            if (exprDataType == TYPE_int) {
                if (idxVal >= theVar->ia->size()) {
                    yyerror("Array index out of range");
                }
                variables ret;
                ret.i = theVar->ia->at(idxVal);
                return ret;
            } else if (exprDataType == TYPE_char) {
                if (idxVal >= theVar->ca->size()) {
                    yyerror("Char array index out of range");
                }
                variables ret;
                ret.c = theVar->ca->at(idxVal);
                return ret;
            }
        }
        return *theVar;
    }

    virtual variables* getMemoryAddress() const override {
        RuntimeRecord *rec = symbolTable.getTop();
        if (rec->locals.find(varName) != rec->locals.end())
            return rec->locals[varName];
        return rec->arguments[varName];
    }

    virtual void semanticCheck() override {
        // If we have indexing, confirm the base is an array type, etc.
        if (indexExpression) {
            indexExpression->semanticCheck();
            indexExpression->confirmType(TYPE_int);
            exprDataType = symbolTable.lookup(varName)->type;
            if (exprDataType == TYPE_int_array) {
                // Using the int array as a single int
                exprDataType = TYPE_int;
            } else if (exprDataType == TYPE_char_array) {
                // Using the char array as a single char
                exprDataType = TYPE_char;
            } else {
                yyerror(("Not an array: " + varName).c_str());
            }
            // Optionally check out-of-bounds if index is a known integer:
            if (typeid(*indexExpression) == typeid(IntegerConstant)) {
                int declaredSize = symbolTable.lookup(varName)->size;
                int idxVal = dynamic_cast<const IntegerConstant*>(indexExpression)->getValue();
                if (idxVal < 0 || idxVal >= declaredSize) {
                    yyerror(("Index out of array bounds in " + varName).c_str());
                }
            }
        } else {
            exprDataType = symbolTable.lookup(varName)->type;
        }
    }

    virtual void printTree(std::ostream &out) const override {
        if (indexExpression) {
            out << "LeftValueID(\n";
            indentationSpaces += "  ";
            out << indentationSpaces << varName << "\n";
            out << indentationSpaces << *indexExpression << "\n";
            indentationSpaces.erase(indentationSpaces.size()-2);
            out << indentationSpaces << ")";
        } else {
            out << "LeftValueID(" << varName << ")";
        }
    }

private:
    std::string        varName;
    ExpressionNode*    indexExpression;
};

/* ----------------------------------------------------------------
   LeftValueString: treat a string literal as a char-array
   ----------------------------------------------------------------*/
class LeftValueString : public LeftValue {
public:
    LeftValueString(std::string *raw) {
        // Strip the surrounding quotes:
        content = raw->substr(1, raw->size() - 2);
    }

    virtual variables evaluate() const override {
        variables v;
        v.ca = new std::vector<char>();
        return v;
    }

    virtual variables* getMemoryAddress() const override {
        // Return a fresh array each time
        variables *slot = new variables();
        slot->ca = new std::vector<char>();
        for (char c : content) {
            slot->ca->push_back(c);
        }
        return slot;
    }

    virtual void semanticCheck() override {
        exprDataType = TYPE_char_array;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "LeftValueString(\"" << content << "\")";
    }

private:
    std::string content;
};

/* ----------------------------------------------------------------
   CompoundStatement: block of statements
   ----------------------------------------------------------------*/
class CompoundStatement : public StatementNode {
public:
    CompoundStatement() {}
    ~CompoundStatement() {
        for (auto s : blockStatements) {
            delete s;
        }
    }

    void addStatement(StatementNode* s) {
        blockStatements.push_back(s);
    }

    virtual void execute() const override {
        for (auto s : blockStatements) {
            s->execute();
        }
    }

    virtual void semanticCheck() override {
        for (auto s : blockStatements) {
            s->semanticCheck();
        }
    }

    virtual void printTree(std::ostream &out) const override {
        out << "CompoundStatement(\n";
        indentationSpaces += "  ";
        for (auto s : blockStatements) {
            out << indentationSpaces << *s << "\n";
        }
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    std::vector<StatementNode*> blockStatements;
};

/* ----------------------------------------------------------------
   VariableDefinition
   ----------------------------------------------------------------*/
class VariableDefinition : public LocalDefinition {
public:
    // scalar
    VariableDefinition(std::string *nm, RType t)
        : varName(*nm), varType(t), arraySize(-1) {}

    // array
    VariableDefinition(std::string *nm, RType t, int length)
        : varName(*nm), arraySize(length)
    {
        if (t == TYPE_int) {
            varType = TYPE_int_array;
        } else if (t == TYPE_char) {
            varType = TYPE_char_array;
        } else {
            yyerror("Invalid array base type for definition");
        }
    }

    virtual void execute() const override {
        // Typically does nothing unless there's global init
    }

    virtual void semanticCheck() override {
        if (arraySize == -1) {
            symbolTable.insert(varName, varType);
        } else {
            symbolTable.insert(varName, varType, arraySize);
        }
    }

    virtual void printTree(std::ostream &out) const override {
        if (arraySize == -1)
            out << "VariableDefinition(" << varName << ", " << varType << ")";
        else
            out << "VariableDefinition(" << varName << ", " << varType
                << ", size=" << arraySize << ")";
    }

    std::string getVarName() const { return varName; }
    RType       getVarType() const { return varType; }
    int         getArraySize()const{ return arraySize; }

private:
    std::string varName;
    RType       varType;
    int         arraySize;
};

/* ----------------------------------------------------------------
   FunctionDefinition
   ----------------------------------------------------------------*/
class FunctionDefinition : public LocalDefinition {
public:
    // No formal params
    FunctionDefinition(std::string *nm, RType retT, DefinitionList* ds, 
                       CompoundStatement* b)
        : funcName(*nm), paramList(nullptr), returnType(retT), funcBody(b)
    {
        if (ds) {
            localDefs = ds->getAll();
            delete ds;
        } else {
            localDefs = new std::vector<LocalDefinition*>();
        }
    }

    // With formal params
    FunctionDefinition(std::string *nm, ParameterList* fpars, RType rt,
                       DefinitionList* ds, CompoundStatement* b)
        : funcName(*nm), returnType(rt), funcBody(b)
    {
        paramList = fpars->getAll();
        delete fpars;
        localDefs = ds->getAll();
        delete ds;
    }

    ~FunctionDefinition() {
        delete funcBody;
        if (paramList) {
            for (auto a : *paramList) delete a;
            delete paramList;
        }
        for (auto l : *localDefs) {
            delete l;
        }
        delete localDefs;
    }

    virtual void semanticCheck() override {
        // Insert itself as a function in the symbol table
        std::vector<RType> *argTypes = new std::vector<RType>();
        symbolTable.insert(funcName, returnType, true, argTypes);

        // New scope
        symbolTable.openScope(returnType);

        if (paramList) {
            for (auto a : *paramList) {
                a->semanticCheck();
                argTypes->push_back(a->getParamType());
            }
        }
        // local declarations
        for (auto d : *localDefs) {
            d->semanticCheck();
        }
        // function body
        funcBody->semanticCheck();

        symbolTable.closeScope();
    }

    virtual void execute() const override {
        std::cout << "Executing function definition: " << funcName << "\n";
        // If you want, replicate local scope logic. 
        contextTracker.openContext();
        RuntimeRecord *ar = symbolTable.getTop();

        // If not supporting function calls with arguments at runtime:
        if (paramList && !paramList->empty()) {
            yyerror("Function with parameters not supported at run time yet");
        }

        // Declare local variables
        for (auto decl : *localDefs) {
            if (typeid(*decl) == typeid(VariableDefinition)) {
                auto *vd = dynamic_cast<VariableDefinition*>(decl);
                if (vd->getArraySize() == -1) {
                    ar->locals[vd->getVarName()] = new variables();
                } else {
                    auto memoryContainer = new variables();
                    if (vd->getVarType() == TYPE_int_array) {
                        memoryContainer->ia->resize(vd->getArraySize());
                    } else if (vd->getVarType() == TYPE_char_array) {
                        memoryContainer->ca->resize(vd->getArraySize());
                    }
                    ar->locals[vd->getVarName()] = memoryContainer;
                }
            } else if (typeid(*decl) == typeid(FunctionDefinition)) {
                auto *fdef = dynamic_cast<FunctionDefinition*>(decl);
                ar->functions[fdef->getName()] = fdef;
            }
        }

        funcBody->execute();
        contextTracker.closeContext();
    }

    virtual void printTree(std::ostream &out) const override {
        out << "FunctionDefinition(\n";
        indentationSpaces += "  ";
        out << indentationSpaces << funcName << "\n";
        if (paramList && !paramList->empty()) {
            out << indentationSpaces << "ParameterList(\n";
            indentationSpaces += "  ";
            for (auto f : *paramList) {
                out << indentationSpaces << *f << "\n";
            }
            indentationSpaces.erase(indentationSpaces.size()-2);
            out << indentationSpaces << ")\n";
        }
        out << indentationSpaces << returnType << "\n";
        if (!localDefs->empty()) {
            out << indentationSpaces << "Locals(\n";
            indentationSpaces += "  ";
            for (auto l : *localDefs) {
                out << indentationSpaces << *l << "\n";
            }
            indentationSpaces.erase(indentationSpaces.size()-2);
            out << indentationSpaces << ")\n";
        }
        out << indentationSpaces << *funcBody << "\n";
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

    std::vector<FunctionParameter*>* getParams()   { return paramList; }
    std::vector<LocalDefinition*>*   getLocals()   { return localDefs; }
    std::string                      getName()   const { return funcName; }
    CompoundStatement*               getBody()   const { return funcBody; }

private:
    std::string                      funcName;
    std::vector<FunctionParameter*> *paramList = nullptr;
    RType                            returnType;
    std::vector<LocalDefinition*>   *localDefs;
    CompoundStatement               *funcBody;
};

/* ----------------------------------------------------------------
   FunctionCall: can be used as ExpressionNode and as StatementNode
   ----------------------------------------------------------------*/
class FunctionCall : public ExpressionNode, public StatementNode {
public:
    FunctionCall(std::string *nm)
        : functionName(*nm)
    {
        args = new std::vector<ExpressionNode*>();
    }

    FunctionCall(std::string *nm, ExpressionSequence *elist)
        : functionName(*nm)
    {
        args = elist->getAll();
        delete elist;
    }

    ~FunctionCall() {
        for (auto a : *args) {
            delete a;
        }
        delete args;
    }

    // Evaluate as expression:
    virtual variables evaluate() const override {
        std::cout << "Evaluating FunctionCall: " << functionName << std::endl;
        RuntimeRecord *ar = symbolTable.getTop();
        if (ar->functions.find(functionName) == ar->functions.end()) {
            // Possibly a builtin function
            handleBuiltin(ar);
        } else {
            // user-defined function
            return invokeUserFunction();
        }
        variables ret;
        ret.i = -1;
        return ret;
    }

    // Execute as statement:
    virtual void execute() const override {
        std::cout << "Executing FunctionCall: " << functionName << std::endl;
        (void) evaluate();
    }

    virtual void semanticCheck() override {
        SymbolsRecord *entry = symbolTable.lookup(functionName);
        exprDataType = entry->type;
        if (!entry->function) {
            yyerror(("Not a function: " + functionName).c_str());
        }
        for (auto arg : *args) {
            arg->semanticCheck();
        }
        // Check arg types:
        std::vector<RType> *argtypes = new std::vector<RType>();
        for (auto arg : *args) {
            argtypes->push_back(arg->getDataType());
        }
        if (argtypes->size() != entry->args->size()) {
            yyerror(("Argument count mismatch in " + functionName).c_str());
        }
        for (size_t i = 0; i < argtypes->size(); i++) {
            if ((*argtypes)[i] != (*entry->args)[i]) {
                std::string msg = "Argument type mismatch in " 
                                  + functionName + " at param index "
                                  + std::to_string(i);
                yyerror(msg.c_str());
            }
        }
        delete argtypes;
    }

    virtual void printTree(std::ostream &out) const override {
        if (args->empty()) {
            out << "FunctionCall(" << functionName << ")";
            return;
        }
        out << "FunctionCall(\n";
        indentationSpaces += "  ";
        out << indentationSpaces << functionName << "\n";
        if (!args->empty()) {
            out << indentationSpaces << "Arguments(\n";
            indentationSpaces += "  ";
            for (auto a : *args) {
                out << indentationSpaces << *a << "\n";
            }
            indentationSpaces.erase(indentationSpaces.size()-2);
            out << indentationSpaces << ")\n";
        }
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    variables invokeUserFunction() const {
        RuntimeRecord *ar = symbolTable.getTop();
        FunctionDefinition *fn = ar->functions[functionName];

        contextTracker.openContext();
        RuntimeRecord *newAr = symbolTable.getTop();

        // Match up formal parameters
        auto *fpars = fn->getParams();
        for (size_t i = 0; i < args->size(); i++) {
            auto *tempFpar = (*fpars)[i];
            auto *tempExpr = (*args)[i];
            if (!tempFpar->isReference()) {
                // pass by value
                variables *val = new variables();
                *val = tempExpr->evaluate();
                newAr->arguments[tempFpar->getName()] = val;
            } else {
                // pass by reference
                auto *idRef = dynamic_cast<LeftValueID*>(tempExpr);
                if (!idRef) {
                    yyerror("Reference param must be a variable");
                }
                newAr->arguments[tempFpar->getName()] = idRef->getMemoryAddress();
            }
        }
        // local definitions
        for (auto decl : *(fn->getLocals())) {
            if (auto vd = dynamic_cast<VariableDefinition*>(decl)) {
                if (vd->getArraySize() == -1) {
                    newAr->locals[vd->getVarName()] = new variables();
                } else {
                    auto space = new variables();
                    if (vd->getVarType() == TYPE_int_array) {
                        space->ia->resize(vd->getArraySize());
                    } else if (vd->getVarType() == TYPE_char_array) {
                        space->ca->resize(vd->getArraySize());
                    }
                    newAr->locals[vd->getVarName()] = space;
                }
            } else if (auto funcd = dynamic_cast<FunctionDefinition*>(decl)) {
                newAr->functions[funcd->getName()] = funcd;
            }
        }

        fn->getBody()->execute();
        variables result = newAr->returnvalue;
        contextTracker.closeContext();
        return result;
    }

    void handleBuiltin(RuntimeRecord *ar) const {
        if (functionName == "writeInteger") {
            variables arg0 = (*args)[0]->evaluate();
            std::cout << arg0.i;
        } else if (functionName == "writeByte") {
            variables arg0 = (*args)[0]->evaluate();
            std::cout << static_cast<char>(arg0.i);
        } else if (functionName == "writeChar") {
            variables arg0 = (*args)[0]->evaluate();
            std::cout << arg0.c;
        } else if (functionName == "writeString") {
            variables arg0 = (*args)[0]->evaluate();
            for (char c : *(arg0.ca)) {
                std::cout << c;
            }
        } else if (functionName == "readInteger") {
            int x; std::cin >> x;
            variables v; v.i = x;
            ar->returnvalue = v;
        }
        else {
            std::string msg = "Unknown built-in function " + functionName;
            yyerror(msg.c_str());
        }
    }

    std::string                   functionName;
    std::vector<ExpressionNode*> *args;
};

/* ----------------------------------------------------------------
   ConditionalUnaryOp: e.g. !cond
   ----------------------------------------------------------------*/
class ConditionalUnaryOp : public ConditionNode {
public:
    ConditionalUnaryOp(char o, ConditionNode* c)
        : op(o), subCond(c) {}
    ~ConditionalUnaryOp() {
        delete subCond;
    }

    virtual variables evaluate() const override {
        variables val = subCond->evaluate();
        // 0 => false, nonzero => true
        variables result;
        result.i = (val.i == 0) ? 1 : 0;
        return result;
    }

    virtual void semanticCheck() override {
        subCond->confirmType(TYPE_int);
        condDataType = TYPE_int;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "ConditionalUnaryOp(" << op << "\n";
        indentationSpaces += "  ";
        out << indentationSpaces << *subCond << "\n";
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    char          op;
    ConditionNode *subCond;
};

/* ----------------------------------------------------------------
   ConditionalBinaryOp: e.g. expr < expr, cond & cond
   ----------------------------------------------------------------*/
class ConditionalBinaryOp : public ConditionNode {
public:
    // expression-based condition
    ConditionalBinaryOp(ExpressionNode* l, char o, ExpressionNode* r)
        : leftExpr(l), op(o), rightExpr(r), leftCond(nullptr), rightCond(nullptr) {}

    // condition-based condition
    ConditionalBinaryOp(ConditionNode* lc, char o, ConditionNode* rc)
        : leftExpr(nullptr), op(o), rightExpr(nullptr), leftCond(lc), rightCond(rc) {}

    ~ConditionalBinaryOp() {
        delete leftExpr;
        delete rightExpr;
        delete leftCond;
        delete rightCond;
    }

    virtual variables evaluate() const override {
        variables result;
        // condition-based:
        if (leftCond) {
            int lv = leftCond->evaluate().i;
            int rv = rightCond->evaluate().i;
            if (op == '&') {
                result.i = (lv != 0 && rv != 0);
            } else if (op == '|') {
                result.i = (lv != 0 || rv != 0);
            }
            return result;
        }
        // expression-based:
        int lv = leftExpr->evaluate().i;
        int rv = rightExpr->evaluate().i;
        switch (op) {
            case '<': result.i = (lv <  rv);  break;
            case '>': result.i = (lv >  rv);  break;
            case 'e': result.i = (lv == rv); break; // 'e' => ==
            case 'n': result.i = (lv != rv); break; // 'n' => !=
            case 'l': result.i = (lv <= rv); break; // 'l' => <=
            case 'm': result.i = (lv >= rv); break; // 'm' => >=
            default : result.i = 0;          break;
        }
        return result;
    }

    virtual void semanticCheck() override {
        // condition-based:
        if (leftCond) {
            leftCond->semanticCheck();
            rightCond->semanticCheck();
            leftCond->confirmType(TYPE_int);
            rightCond->confirmType(TYPE_int);
            condDataType = TYPE_int;
            return;
        }
        // expression-based:
        leftExpr->semanticCheck();
        rightExpr->semanticCheck();
        leftExpr->confirmType(rightExpr->getDataType());
        condDataType = TYPE_int;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "ConditionalBinaryOp(" << op << "\n";
        indentationSpaces += "  ";
        if (leftCond) {
            out << indentationSpaces << *leftCond << "\n";
            out << indentationSpaces << *rightCond << "\n";
        } else {
            out << indentationSpaces << *leftExpr << "\n";
            out << indentationSpaces << *rightExpr << "\n";
        }
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    // expression-based
    ExpressionNode *leftExpr;
    char            op;
    ExpressionNode *rightExpr;

    // condition-based
    ConditionNode  *leftCond;
    ConditionNode  *rightCond;
};

/* ----------------------------------------------------------------
   BooleanConstant (true/false)
   ----------------------------------------------------------------*/
class BooleanConstant : public ConditionNode {
public:
    BooleanConstant(bool b) : value(b) {}

    virtual variables evaluate() const override {
        variables v;
        v.i = value ? 1 : 0;
        return v;
    }

    virtual void semanticCheck() override {
        condDataType = TYPE_int;
    }

    virtual void printTree(std::ostream &out) const override {
        out << "BooleanConstant(" << (value ? "true" : "false") << ")";
    }

private:
    bool value;
};

/* ----------------------------------------------------------------
   EmptyStatement (like ';')
   ----------------------------------------------------------------*/
class EmptyStatement : public StatementNode {
public:
    virtual void execute() const override {
        // do nothing
    }
    virtual void semanticCheck() override {
        // no checks
    }
    virtual void printTree(std::ostream &out) const override {
        out << "EmptyStatement";
    }
};

/* ----------------------------------------------------------------
   AssignmentStatement: lvalue = expr
   ----------------------------------------------------------------*/
class AssignmentStatement : public StatementNode {
public:
    AssignmentStatement(LeftValueID* lv, ExpressionNode* e)
        : target(lv), assignedValue(e) {}
    ~AssignmentStatement() {
        delete target;
        delete assignedValue;
    }

    virtual void execute() const override {
        variables *mem = target->getMemoryAddress();
        *mem = assignedValue->evaluate();
    }

    virtual void semanticCheck() override {
        target->semanticCheck();
        assignedValue->semanticCheck();
        target->confirmType(assignedValue->getDataType());
    }

    virtual void printTree(std::ostream &out) const override {
        out << "AssignmentStatement(\n";
        indentationSpaces += "  ";
        out << indentationSpaces << *target << "\n";
        out << indentationSpaces << *assignedValue << "\n";
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    LeftValue      *target;
    ExpressionNode *assignedValue;
};

/* ----------------------------------------------------------------
   IfStatement
   ----------------------------------------------------------------*/
class IfStatement : public StatementNode {
public:
    IfStatement(ConditionNode* c, StatementNode* th)
        : condition(c), thenPart(th), elsePart(nullptr) {}
    IfStatement(ConditionNode* c, StatementNode* th, StatementNode* el)
        : condition(c), thenPart(th), elsePart(el) {}
    ~IfStatement() {
        delete condition;
        delete thenPart;
        if (elsePart) delete elsePart;
    }

    virtual void execute() const override {
        if (condition->evaluate().i)
            thenPart->execute();
        else if (elsePart)
            elsePart->execute();
    }

    virtual void semanticCheck() override {
        condition->confirmType(TYPE_int);
        thenPart->semanticCheck();
        if (elsePart)
            elsePart->semanticCheck();
    }

    virtual void printTree(std::ostream &out) const override {
        out << "IfStatement(\n";
        indentationSpaces += "  ";
        out << indentationSpaces << *condition << "\n";
        out << indentationSpaces << *thenPart << "\n";
        if (elsePart)
            out << indentationSpaces << *elsePart << "\n";
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    ConditionNode *condition;
    StatementNode *thenPart;
    StatementNode *elsePart;
};

/* ----------------------------------------------------------------
   WhileLoop statement
   ----------------------------------------------------------------*/
class WhileLoop : public StatementNode {
public:
    WhileLoop(ConditionNode* c, StatementNode* b)
        : condition(c), body(b) {}
    ~WhileLoop() {
        delete condition;
        delete body;
    }

    virtual void execute() const override {
        while (condition->evaluate().i)
            body->execute();
    }

    virtual void semanticCheck() override {
        condition->confirmType(TYPE_int);
        body->semanticCheck();
    }

    virtual void printTree(std::ostream &out) const override {
        out << "WhileLoop(\n";
        indentationSpaces += "  ";
        out << indentationSpaces << *condition << "\n";
        out << indentationSpaces << *body << "\n";
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    ConditionNode *condition;
    StatementNode *body;
};

/* ----------------------------------------------------------------
   ReturnStatement
   ----------------------------------------------------------------*/
class ReturnStatement : public StatementNode {
public:
    ReturnStatement() : returnExpr(nullptr) {}
    ReturnStatement(ExpressionNode* e) : returnExpr(e) {}
    ~ReturnStatement() {
        delete returnExpr;
    }

    virtual void execute() const override {
        if (returnExpr) {
            variables val = returnExpr->evaluate();
            RuntimeRecord *ar = contextTracker.getTop();
            ar->returnvalue = val;
        }
    }

    virtual void semanticCheck() override {
        if (returnExpr) {
            returnExpr->semanticCheck();
            returnExpr->confirmType(symbolTable.getReturnType());
        } else {
            if (symbolTable.getReturnType() != TYPE_void) {
                yyerror("Return type mismatch for non-void function");
            }
        }
    }

    virtual void printTree(std::ostream &out) const override {
        if (!returnExpr) {
            out << "ReturnStatement()";
            return;
        }
        out << "ReturnStatement(\n";
        indentationSpaces += "  ";
        out << indentationSpaces << *returnExpr << "\n";
        indentationSpaces.erase(indentationSpaces.size()-2);
        out << indentationSpaces << ")";
    }

private:
    ExpressionNode *returnExpr;
};

#endif // AST_NODES_HPP__
