%{
#include <cstdio>
#include "ast.hpp"
#include "lexer.hpp"

#define YYLTYPE_IS_TRIVIAL 1
#define YYERROR_VERBOSE 1

// Global symbol/context tables renamed in ast.hpp:
SymbolsManager symbolTable;
RuntimeContext contextTracker;
std::string indentationSpaces;
%}

// Enable location tracking
%locations

// Token definitions
%token T_byte      "byte"
%token T_int       "int"
%token T_if        "if"
%token T_else      "else"
%token T_true      "true"
%token T_false     "false"
%token T_proc      "proc"
%token T_reference "reference"
%token T_return    "return"
%token T_while     "while"

// Typed tokens
%token<var>       T_id
%token<num>       T_const
%token<character> T_char
%token<var>       T_string

%token T_equal   "=="
%token T_notEq   "!="
%token T_lessEq  "<="
%token T_moreEq  ">="

%left<op> '|'
%left<op> '&'
%nonassoc<op> "==" "!=" '>' '<' "<=" ">="
%left<op> '+' '-'
%left<op> '*' '/' '%'
%nonassoc<op> '!'

%expect 1

%union {
    ExpressionSequence *expressions;
    ExpressionNode     *expression;
    StatementNode      *statement;
    CompoundStatement  *compoundNode;
    LocalDefinition    *localDef;
    DefinitionList     *defList;
    ParameterList      *fparList;
    FunctionParameter  *singleFpar;
    FunctionCall       *funcInvocation;
    LeftValue          *lval;
    ConditionNode      *condition;

    RType               rtype;
    std::string        *var;
    int                 num;
    char                character;
    char                op;
}

// Nonterminals:
%type<localDef>       local_definition functionDefinition variableDefinition
%type<defList>        local_definition_list
%type<fparList>       fpar_list
%type<singleFpar>     fpar_def
%type<rtype>          data_type r_type typeSpec
%type<statement>      stmt
%type<compoundNode>   compound_stmt compound_stmt_helper
%type<funcInvocation> func_call
%type<expressions>    expr_list
%type<expression>     expr
%type<lval>           l_value
%type<condition>      cond

%%

//-------------------------------
// PROGRAM (start symbol)
//-------------------------------
functionDefinition:
    T_id '(' fpar_list ')' ':' r_type local_definition_list compound_stmt
    {
        // With formal parameters
        $$ = new FunctionDefinition($1, $3, $6, $7, $8);
        $$->setLine(@1.first_line);
        // Perform semantic check & can execute if desired:
        $$->semanticCheck();
        // $$->execute();
    }
  | T_id '(' ')' ':' r_type local_definition_list compound_stmt
    {
        // No formal parameters
        $$ = new FunctionDefinition($1, $5, $6, $7);
        $$->setLine(@1.first_line);
        $$->semanticCheck();
        // $$->execute();
    }
;

// If you intend to parse multiple top-level functions,
// you could define another rule wrapping them, but
// for demonstration, we keep a single top-level function.

//-------------------------------
// LOCAL DEFINITION LIST
//-------------------------------
local_definition_list:
    /* empty */
    {
        $$ = new DefinitionList();
    }
  | local_definition_list local_definition
    {
        $1->addDefinition($2);
        $$ = $1;
    }
;

//-------------------------------
// FORMAL PARAMETER LIST
//-------------------------------
fpar_list:
    fpar_def
    {
        $$ = new ParameterList();
        $$->addParameter($1);
    }
  | fpar_list ',' fpar_def
    {
        $1->addParameter($3);
        $$ = $1;
    }
;

fpar_def:
    T_id ':' T_reference typeSpec
    {
        $$ = new FunctionParameter($1, true, $4);
        $$->setLine(@1.first_line);
    }
  | T_id ':' typeSpec
    {
        $$ = new FunctionParameter($1, false, $3);
        $$->setLine(@1.first_line);
    }
;

//-------------------------------
// TYPE PRODUCTION
//-------------------------------
data_type:
    T_int  { $$ = TYPE_int; }
  | T_byte { $$ = TYPE_char; }
;

typeSpec:
    data_type
    {
        $$ = $1;
    }
  | data_type '[' ']'
    {
        if ($1 == TYPE_int) $$ = TYPE_int_array;
        else                $$ = TYPE_char_array;
    }
;

r_type:
    data_type
    {
        $$ = $1;
    }
  | T_proc
    {
        $$ = TYPE_void;
    }
;

//-------------------------------
// LOCAL DEFINITION
//-------------------------------
local_definition:
    functionDefinition
    {
        $$ = $1;
    }
  | variableDefinition
    {
        $$ = $1;
    }
;

//-------------------------------
// VARIABLE DEFINITION
//-------------------------------
variableDefinition:
    T_id ':' data_type ';'
    {
        $$ = new VariableDefinition($1, $3);
        $$->setLine(@1.first_line);
    }
  | T_id ':' data_type '[' T_const ']' ';'
    {
        $$ = new VariableDefinition($1, $3, $5);
        $$->setLine(@1.first_line);
    }
;

//-------------------------------
// STATEMENT
//-------------------------------
stmt:
    ';'
    {
        $$ = new EmptyStatement();
        $$->setLine(@1.first_line);
    }
  | l_value '=' expr ';'
    {
        $$ = new AssignmentStatement(dynamic_cast<LeftValueID*>($1), $3);
        $$->setLine(@1.first_line);
    }
  | compound_stmt
    {
        $$ = $1;
    }
  | func_call ';'
    {
        // cast to StatementNode if needed, but FunctionCall is both
        $$ = $1;
    }
  | T_if '(' cond ')' stmt
    {
        $$ = new IfStatement($3, $5);
        $$->setLine(@1.first_line);
    }
  | T_if '(' cond ')' stmt T_else stmt
    {
        $$ = new IfStatement($3, $5, $7);
        $$->setLine(@1.first_line);
    }
  | T_while '(' cond ')' stmt
    {
        $$ = new WhileLoop($3, $5);
        $$->setLine(@1.first_line);
    }
  | T_return ';'
    {
        $$ = new ReturnStatement();
        $$->setLine(@1.first_line);
    }
  | T_return expr ';'
    {
        $$ = new ReturnStatement($2);
        $$->setLine(@1.first_line);
    }
;

//-------------------------------
// COMPOUND STATEMENT
//-------------------------------
compound_stmt:
    '{' compound_stmt_helper '}'
    {
        $$ = $2;
    }
;

compound_stmt_helper:
    /* empty */
    {
        $$ = new CompoundStatement();
    }
  | compound_stmt_helper stmt
    {
        $1->addStatement($2);
        $$ = $1;
    }
;

//-------------------------------
// FUNCTION CALL
//-------------------------------
func_call:
    T_id '(' ')'
    {
        $$ = new FunctionCall($1);
        $$->ExpressionNode::setLine(@1.first_line);
    }
  | T_id '(' expr_list ')'
    {
        $$ = new FunctionCall($1, $3);
        $$->ExpressionNode::setLine(@1.first_line);
    }
;

//-------------------------------
// EXPRESSION LIST
//-------------------------------
expr_list:
    expr
    {
        $$ = new ExpressionSequence();
        $$->addExpression($1);
    }
  | expr_list ',' expr
    {
        $1->addExpression($3);
        $$ = $1;
    }
;

//-------------------------------
// EXPRESSIONS
//-------------------------------
expr:
    T_const
    {
        $$ = new IntegerConstant($1);
        $$->setLine(@1.first_line);
    }
  | T_char
    {
        $$ = new CharConstant($1);
        $$->setLine(@1.first_line);
    }
  | l_value
    {
        $$ = $1;
    }
  | '(' expr ')'
    {
        $$ = $2;
    }
  | func_call
    {
        $$ = $1;
    }
  | '+' expr
    {
        $$ = new UnaryOpExpression($1, $2);
        $$->setLine(@1.first_line);
    }
  | '-' expr
    {
        $$ = new UnaryOpExpression($1, $2);
        $$->setLine(@1.first_line);
    }
  | expr '+' expr
    {
        $$ = new BinaryOpExpression($1, $2, $3);
        $$->setLine(@2.first_line);
    }
  | expr '-' expr
    {
        $$ = new BinaryOpExpression($1, $2, $3);
        $$->setLine(@2.first_line);
    }
  | expr '*' expr
    {
        $$ = new BinaryOpExpression($1, $2, $3);
        $$->setLine(@2.first_line);
    }
  | expr '/' expr
    {
        $$ = new BinaryOpExpression($1, $2, $3);
        $$->setLine(@2.first_line);
    }
  | expr '%' expr
    {
        $$ = new BinaryOpExpression($1, $2, $3);
        $$->setLine(@2.first_line);
    }
;

//-------------------------------
// L-VALUE
//-------------------------------
l_value:
    T_id
    {
        $$ = new LeftValueID($1);
        $$->setLine(@1.first_line);
    }
  | T_id '[' expr ']'
    {
        $$ = new LeftValueID($1, $3);
        $$->setLine(@1.first_line);
    }
  | T_string
    {
        $$ = new LeftValueString($1);
        $$->setLine(@1.first_line);
    }
;

//-------------------------------
// CONDITIONS
//-------------------------------
cond:
    T_true
    {
        $$ = new BooleanConstant(true);
        $$->setLine(@1.first_line);
    }
  | T_false
    {
        $$ = new BooleanConstant(false);
        $$->setLine(@1.first_line);
    }
  | '(' cond ')'
    {
        $$ = $2;
    }
  | '!' cond
    {
        $$ = new ConditionalUnaryOp($1, $2);
        $$->setLine(@1.first_line);
    }
  | expr T_equal expr
    {
        $$ = new ConditionalBinaryOp($1, 'e', $3);
        $$->setLine(@2.first_line);
    }
  | expr T_notEq expr
    {
        $$ = new ConditionalBinaryOp($1, 'n', $3);
        $$->setLine(@2.first_line);
    }
  | expr '<' expr
    {
        $$ = new ConditionalBinaryOp($1, '<', $3);
        $$->setLine(@2.first_line);
    }
  | expr '>' expr
    {
        $$ = new ConditionalBinaryOp($1, '>', $3);
        $$->setLine(@2.first_line);
    }
  | expr T_lessEq expr
    {
        $$ = new ConditionalBinaryOp($1, 'l', $3);
        $$->setLine(@2.first_line);
    }
  | expr T_moreEq expr
    {
        $$ = new ConditionalBinaryOp($1, 'm', $3);
        $$->setLine(@2.first_line);
    }
  | cond '&' cond
    {
        $$ = new ConditionalBinaryOp($1, '&', $3);
        $$->setLine(@2.first_line);
    }
  | cond '|' cond
    {
        $$ = new ConditionalBinaryOp($1, '|', $3);
        $$->setLine(@2.first_line);
    }
;

%%

//-------------------------------
// MAIN
//-------------------------------
int main() {
    int parseResult = yyparse();
    if (parseResult == 0)
        printf("Success.\n");
    return parseResult;
}


