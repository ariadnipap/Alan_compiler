#ifndef SYMBOL_MANAGER_HPP__
#define SYMBOL_MANAGER_HPP__

#include <string>
#include <vector>
#include <map>

class FunctionDefinition;

// Data type enum:
enum RType { TYPE_int, TYPE_int_array, TYPE_char, TYPE_char_array, TYPE_void, TYPE_string };

// A union for storing different data in runtime:
union variables {
    int                i;
    char               c;
    std::vector<char> *ca;
    std::vector<int>  *ia;
};

void yyerror(const char *msg);

// Represents an entry in the symbol table:
struct SymbolsRecord {
    RType type;
    int   size;
    bool  function;
    std::vector<RType> *args;
    SymbolsRecord() {}
    SymbolsRecord(RType t)
        : type(t), function(false), args(nullptr), size(-1) {}
    SymbolsRecord(RType t, bool f, std::vector<RType> *a)
        : type(t), function(f)
    {
        size = -1;
        if (f) {
            if (a != nullptr) {
                args = a;
            } else {
                args = new std::vector<RType>();
            }
        } else {
            args = nullptr;
        }
    }
    SymbolsRecord(RType t, int s)
        : type(t), size(s), function(false), args(nullptr) {}
};

class SymbolScope {
public:
    SymbolScope() {
        scopeSize = 0;
        returnTypeInScope = TYPE_void;
    }
    SymbolScope(RType t) {
        scopeSize = 0;
        returnTypeInScope = t;
    }

    RType getReturnType() const {
        return returnTypeInScope;
    }

    SymbolsRecord* lookup(const std::string &name) {
        if (mapRecords.find(name) == mapRecords.end()) return nullptr;
        return &mapRecords[name];
    }

    void insert(const std::string &name, RType t) {
        if (mapRecords.find(name) != mapRecords.end())
            yyerror("Duplicate entry in scope");
        mapRecords[name] = SymbolsRecord(t);
        ++scopeSize;
    }
    void insert(const std::string &name, RType t, bool f, std::vector<RType> *args) {
        if (mapRecords.find(name) != mapRecords.end())
            yyerror("Duplicate entry in scope");
        mapRecords[name] = SymbolsRecord(t, f, args);
        ++scopeSize;
    }
    void insert(const std::string &name, RType t, int s) {
        if (mapRecords.find(name) != mapRecords.end())
            yyerror("Duplicate entry in scope");
        mapRecords[name] = SymbolsRecord(t, s);
        scopeSize += s;
    }

    int getSize() const { return scopeSize; }

private:
    std::map<std::string, SymbolsRecord> mapRecords;
    int  scopeSize;
    RType returnTypeInScope;
};


struct RuntimeRecord {
    std::map<std::string, variables *> locals;
    std::map<std::string, variables *> arguments;
    std::map<std::string, FunctionDefinition*> functions;
    variables returnvalue;
};


class RuntimeContext {
public:
    RuntimeContext() {}
    void openContext() {
        contexts.push_back(new RuntimeRecord());
    }
    void closeContext() {
        contexts.pop_back();
    }
    RuntimeRecord* getTop() {
        return contexts.back();
    }
private:
    std::vector<RuntimeRecord*> contexts;
};

extern RuntimeContext contextTracker;

class SymbolsManager {
public:
    SymbolsManager() {
        openScope(TYPE_void);

        // Initialize built-in functions:
        std::vector<RType> *args1 = new std::vector<RType>();
        args1->push_back(TYPE_int);
        insert("writeInteger", TYPE_void, true, args1);

        std::vector<RType> *args2 = new std::vector<RType>();
        args2->push_back(TYPE_char);
        insert("writeByte", TYPE_void, true, args2);

        std::vector<RType> *args3 = new std::vector<RType>();
        args3->push_back(TYPE_char);
        insert("writeChar", TYPE_void, true, args3);

        std::vector<RType> *args4 = new std::vector<RType>();
        args4->push_back(TYPE_char_array);
        insert("writeString", TYPE_void, true, args4);

        insert("readInteger", TYPE_int, true, nullptr);
        insert("readByte", TYPE_char, true, nullptr);
        insert("readChar", TYPE_char, true, nullptr);

        std::vector<RType> *args5 = new std::vector<RType>();
        args5->push_back(TYPE_char_array);
        insert("readString", TYPE_void, true, args5);

        std::vector<RType> *args6 = new std::vector<RType>();
        args6->push_back(TYPE_char);
        insert("extend", TYPE_int, true, args6);

        std::vector<RType> *args7 = new std::vector<RType>();
        args7->push_back(TYPE_int);
        insert("shrink", TYPE_char, true, args7);

        std::vector<RType> *args8 = new std::vector<RType>();
        args8->push_back(TYPE_char_array);
        insert("strlen", TYPE_int, true, args8);

        std::vector<RType> *args9 = new std::vector<RType>();
        args9->push_back(TYPE_char_array);
        args9->push_back(TYPE_char_array);
        insert("strcmp", TYPE_int, true, args9);

        std::vector<RType> *args10 = new std::vector<RType>();
        args10->push_back(TYPE_char_array);
        args10->push_back(TYPE_char_array);
        insert("strcpy", TYPE_void, true, args10);

        std::vector<RType> *args11 = new std::vector<RType>();
        args11->push_back(TYPE_char_array);
        args11->push_back(TYPE_char_array);
        insert("strcat", TYPE_void, true, args11);
    }

    void openScope() {
        scopes.push_back(SymbolScope());
    }
    void openScope(RType t) {
        scopes.push_back(SymbolScope(t));
    }

    void closeScope() {
        scopes.pop_back();
    }

    RType getReturnType() const {
        return scopes.back().getReturnType();
    }

    SymbolsRecord* lookup(const std::string &name) {
        for (auto i = scopes.rbegin(); i != scopes.rend(); i++) {
            SymbolsRecord * entry = i->lookup(name);
            if (entry != nullptr) {
                return entry;
            }
        }
        std::string errMsg = "Symbol not found: " + name;
        yyerror(errMsg.c_str());
        return nullptr;
    }

    void insert(const std::string &name, RType t) {
        scopes.back().insert(name, t);
    }
    void insert(const std::string &name, RType t, bool f, std::vector<RType> *args) {
        scopes.back().insert(name, t, f, args);
    }
    void insert(const std::string &name, RType t, int s) {
        scopes.back().insert(name, t, s);
    }

    int getSize() const {
        return scopes.back().getSize();
    }

    RuntimeRecord* getTop() {
        return contextTracker.getTop();
    }

private:
    std::vector<SymbolScope> scopes;
};

extern SymbolsManager symbolTable;


#endif // SYMBOL_MANAGER_HPP__
