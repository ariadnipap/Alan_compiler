%option noyywrap

%{
#include <cstdio>
#include <cstdlib>
#include "ast.hpp"
#include "lexer.hpp"
#include "parser.hpp"

#define T_eof       0


int lineno = 1;
int c_stack = 0;

inline void setLoc() {
    yylloc.first_line = lineno;
    yylloc.last_line = lineno;
}

%}

L [A-Za-z]
D [0-9]
W [ \t\r]
H [0-9a-f]



%x COMMENT

%%

"byte"              {setLoc(); return T_byte;}
"int"               {setLoc(); return T_int;}
"if"                {setLoc(); return T_if;}
"else"              {setLoc(); return T_else;}
"true"              {setLoc(); return T_true;}
"false"             {setLoc(); return T_false;}
"proc"              {setLoc(); return T_proc;}
"reference"         {setLoc(); return T_reference;}
"return"            {setLoc(); return T_return;}
"while"             {setLoc(); return T_while;}

{L}({L}|{D}|_)*     {yylval.var = new std::string(yytext); return T_id;}
{D}+                {yylval.num = atoi(yytext); return T_const;}
\x22([^\x22\n]|"\\\"")*\x22     {yylval.var = new std::string(yytext); return T_string;}
\x27([^']|"\\"([ntr0\\\'\"]|"x"{H}{H}))\x27      {yylval.character = yytext[1]; return T_char;}

[\(\)\{\}\[\]\=\+\-\*\/\%\!\&\|\>\<\:\;\,]  {yylval.op = yytext[0]; return yytext[0];}

"=="                {yylval.op = 'e'; return T_equal;}
"!="                {yylval.op = 'n'; return T_notEq;}
"<="                {yylval.op = 'l'; return T_lessEq;}
">="                {yylval.op = 'm'; return T_moreEq;}

\n                  { ++lineno; }
{W}+                { /* nothing */ }
"--".*"\n"          { ++lineno; }
"--"[^\n\x00]*      { /* nothing */ }

"(*"                {++c_stack; BEGIN(COMMENT);}
<COMMENT>"(*"       {++c_stack;}
<COMMENT>"*)"       {--c_stack; if (c_stack == 0) BEGIN(INITIAL);}
<COMMENT>\n         {lineno++;}
<COMMENT>"*"        { /* nothing */ }
<COMMENT>[^*\n]+    { /* nothing */ }               



.                   { yyerror("lexical error"); }


%%

void yyerror(const char *s) {
     fprintf(stderr, "Error at line %d, column %d: %s\n",
        yylloc.first_line, yylloc.first_column, s);
    exit(1);
}