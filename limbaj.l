%{
#include <stdio.h>
#include <cstring>
#include "limbaj.tab.h"
%}
%option noyywrap
%%
"main"                                             { return MAIN; }
"action"                                           { return FUNC_DECL; }

"eval"                                             { return EVAL; }
"typeof"                                           { return TYPEOF; }

"nomod"|"mod"                                      { yylval.stringVal = strdup(yytext); return VAR_MOD; }

"class"                                            { return CLASS; }
"constructor"                                      { return CONSTRUCTOR; }
"public"|"private"                                 { return ACC_MOD; }

"integer"|"float"|"char"|"string"|"boolean"|"void" { yylval.stringVal = strdup(yytext); return TYPE; }

"if"                                               { return IF; }
"else"                                             { return ELSE; }
"while"                                            { return WHILE; }
"for"                                              { return FOR; }
"return"                                           { return RETURN; }

"true"|"false"                                     { if(strcmp(yytext, "true") == 0){ yylval.boolVal = true; } else { yylval.boolVal = false; }; return BOOL_VALUE; }

"<="|"<"|">="|">"|"=="|"!="                        { yylval.stringVal = strdup(yytext); return REL_OP; }
"!"                                                { return NOT; }

"+"                                                { return PLUS; }
"-"                                                { return MINUS; }
"*"                                                { return TIMES; }
"/"                                                { return DIVIDE; }
"%"                                                { return MOD; }

"#"                                                { return CONCAT;}

"&&"                                               { return AND; }
"||"                                               { return OR; }

"="                                                { return ASSIGN; }

-?(0|([1-9][0-9]*))\.[0-9]+                        { yylval.floatVal = atof(yytext); return FLOAT_VALUE; }
0|(-?[1-9][0-9]*)                                  { yylval.intVal = atoi(yytext); return INT_VALUE; }
[a-zA-Z|_][a-zA-Z0-9|_]*                           { yylval.stringVal = strdup(yytext); return ID; }
\"[^\"]*\"                                         { yylval.stringVal = strdup(yytext); return STRING_VALUE; }
\'[^\']*\'                                         { yylval.charVal = yytext[1]; return CHAR_VALUE; }
[ \t]                                              ;
\n                                                 { yylineno++; }
.                                                  {return yytext[0];}
