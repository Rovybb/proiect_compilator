%{
#include "symbol_table.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
using namespace std;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yydebug;
extern int yylex();
void yyerror(const char * s);
std::vector<struct Variable*> params;
char scope[100];
char prev_scope[100];
%}

%union {
    char *stringVal;
    char charVal;
    int intVal;
    float floatVal;
    bool boolVal;
    struct expr_str *expr_node;
}

%token FUNC_DECL MAIN CLASS CONSTRUCTOR ACC_MOD
%token EVAL TYPEOF
%token IF ELSE WHILE FOR RETURN
%token ASSIGN PLUS MINUS TIMES DIVIDE MOD
%token NOT AND OR

%token<stringVal> STRING_VALUE ID TYPE VAR_MOD REL_OP
%token<charVal> CHAR_VALUE
%token<intVal> INT_VALUE
%token<floatVal> FLOAT_VALUE
%token<boolVal> BOOL_VALUE

%type<expr_node> number_expression
%type<expr_node> string_expression
%type<expr_node> bool_expression
%type<expr_node> expression
%type<expr_node> func_call

%left OR
%left AND
%left REL_OP
%left NOT
%left PLUS MINUS
%left TIMES DIVIDE MOD CONCAT
%left '(' ')' ','

%start initial
%%
initial: {strcpy(scope, strdup("global"));} class_section globalVar_section func_section main_section {printf("Correct\n");}
       ;

eval_func: EVAL '(' number_expression ')' {printf("Eval - line %d: %d\n", yylineno, $3->int_val);}
         | EVAL '(' bool_expression ')' {char *val; if ($3->bool_val) { val = strdup("true"); } else { val = strdup("false"); };printf("Eval - line %d: %s\n", yylineno, val);}
         ;

typeof_func: TYPEOF '(' ID ')' {printf("Typeof - line %d: %s\n", yylineno, strdup(type_of_def($3, scope)));}
           ;

globalVar_section: globalVar_section create_global_variable
                 | create_global_variable
                 ;

func_section: func_section function
            | function
            ;

function: FUNC_DECL ID {strcpy(prev_scope, scope); strcpy(scope, $2);} '(' param_list_opt ')' ':' TYPE {add_function($2, $8, prev_scope, params); params.clear();} '{' func_body '}' {strcpy(scope, strdup("global"));}
        ;

param_list_opt: 
              | param_list
              ;

param_list: param_list ',' param
          | param
          ;

param: ID ':' TYPE {Variable* temp = create_param($1, $3, scope); params.push_back(temp);}
     ;

func_body: func_body statement
         | statement
         ;

statement: assign_variable ';'
         | update_variable ';'
         | if_statement
         | while_statement
         | for_statement
         | func_call ';'
         | return_statement ';'
         | eval_func ';'
         | typeof_func ';'
         ;

assign_variable: VAR_MOD ID ':' TYPE {bool isConst; if(strcmp($1, "nomod") == 0){isConst = true;} else {isConst = false;} expr_str *temp = create_empty_value($4); add_variable($2, $4, scope, isConst, temp);}
               | VAR_MOD ID '[' INT_VALUE ']' ':' TYPE {bool isConst; if(strcmp($1, "nomod") == 0){isConst = true;} else {isConst = false;} add_vector($2, $7, scope, $4, isConst);}
               | VAR_MOD ID ':' TYPE ASSIGN expression {bool isConst; if(strcmp($1, "nomod") == 0){isConst = true;} else {isConst = false;} add_variable($2, $4, scope, isConst, $6);}
               ;

update_variable: ID ASSIGN expression {update_variable($1, scope, $3);}
               | ID '[' INT_VALUE ']' ASSIGN expression {expr_str* temp = convert_int($3); update_vector($1, scope, temp, $6);}
               | ID '[' ID ']' ASSIGN expression {expr_str* temp = convert_from_id($3, scope); update_vector($1, scope, temp, $6);}
               ;

create_global_variable: VAR_MOD ID ':' TYPE ';' {bool isConst; if(strcmp($1, "nomod") == 0){isConst = true;} else {isConst = false;} expr_str *temp = create_empty_value($4); add_variable($2, $4, scope, isConst, temp);}
                      | VAR_MOD ID ':' TYPE ASSIGN expression ';'  {bool isConst; if(strcmp($1, "nomod") == 0){isConst = true;} else {isConst = false;} add_variable($2, $4, scope, isConst, $6);}
                      | VAR_MOD ID '[' INT_VALUE ']' ':' TYPE ';' {bool isConst; if(strcmp($1, "nomod") == 0){isConst = true;} else {isConst = false;} add_vector($2, $7, scope, $4, isConst);}
                      ;

if_statement: IF '(' bool_expression ')' '{' statement '}' ELSE '{' statement '}'
            | IF '(' bool_expression ')' '{' statement '}'
            ;

while_statement: WHILE '(' bool_expression ')' '{' statement '}'
               ;

for_statement: FOR '(' assign_variable ';' bool_expression ';' update_variable ')' '{' statement '}'

return_statement: RETURN expression
                | RETURN
                ;

expression: number_expression  {$$ = $1;}
          | string_expression  {$$ = $1;}
          | bool_expression    {$$ = $1;}
          | func_call          {$$ = $1;}
          | ID                 {$$ = convert_from_id($1, scope);}
          ;

number_expression: ID PLUS number_expression                 {expr_str* temp = convert_from_id($1, scope); $$ = num_expresion(temp, $3, '+');}
                 | ID PLUS ID                                {expr_str* temp1 = convert_from_id($1, scope); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '+');}
                 | ID MINUS number_expression                {expr_str* temp = convert_from_id($1, scope); $$ = num_expresion(temp, $3, '-');}
                 | ID MINUS ID                               {expr_str* temp1 = convert_from_id($1, scope); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '-');}
                 | ID TIMES number_expression                {expr_str* temp = convert_from_id($1, scope); $$ = num_expresion(temp, $3, '*');}
                 | ID TIMES ID                               {expr_str* temp1 = convert_from_id($1, scope); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '*');}
                 | ID DIVIDE number_expression               {expr_str* temp = convert_from_id($1, scope); $$ = num_expresion(temp, $3, '/');}
                 | ID DIVIDE ID                              {expr_str* temp1 = convert_from_id($1, scope); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '/');}
                 | ID MOD number_expression                  {expr_str* temp = convert_from_id($1, scope); $$ = num_expresion(temp, $3, '%');}
                 | ID MOD ID                                 {expr_str* temp1 = convert_from_id($1, scope); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '%');}
    
                 | INT_VALUE PLUS number_expression          {expr_str* temp = convert_int($1); $$ = num_expresion(temp, $3, '+');}
                 | INT_VALUE PLUS ID                         {expr_str* temp1 = convert_int($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '+');}
                 | INT_VALUE MINUS number_expression         {expr_str* temp = convert_int($1); $$ = num_expresion(temp, $3, '-');}
                 | INT_VALUE MINUS ID                        {expr_str* temp1 = convert_int($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '-');}
                 | INT_VALUE TIMES number_expression         {expr_str* temp = convert_int($1); $$ = num_expresion(temp, $3, '*');}
                 | INT_VALUE TIMES ID                        {expr_str* temp1 = convert_int($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '*');}
                 | INT_VALUE DIVIDE number_expression        {expr_str* temp = convert_int($1); $$ = num_expresion(temp, $3, '/');}
                 | INT_VALUE DIVIDE ID                       {expr_str* temp1 = convert_int($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '/');}
                 | INT_VALUE MOD number_expression           {expr_str* temp = convert_int($1); $$ = num_expresion(temp, $3, '%');} 
                 | INT_VALUE MOD ID                          {expr_str* temp1 = convert_int($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '%');}
     
                 | FLOAT_VALUE PLUS number_expression        {expr_str* temp = convert_float($1); $$ = num_expresion(temp, $3, '+');}
                 | FLOAT_VALUE PLUS ID                       {expr_str* temp1 = convert_float($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '+');}
                 | FLOAT_VALUE MINUS number_expression       {expr_str* temp = convert_float($1); $$ = num_expresion(temp, $3, '-');}
                 | FLOAT_VALUE MINUS ID                      {expr_str* temp1 = convert_float($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '-');}
                 | FLOAT_VALUE TIMES number_expression       {expr_str* temp = convert_float($1); $$ = num_expresion(temp, $3, '*');}
                 | FLOAT_VALUE TIMES ID                      {expr_str* temp1 = convert_float($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '*');}
                 | FLOAT_VALUE DIVIDE number_expression      {expr_str* temp = convert_float($1); $$ = num_expresion(temp, $3, '/');}
                 | FLOAT_VALUE DIVIDE ID                     {expr_str* temp1 = convert_float($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '/');}
                 | FLOAT_VALUE MOD number_expression         {expr_str* temp = convert_float($1); $$ = num_expresion(temp, $3, '%');}
                 | FLOAT_VALUE MOD ID                        {expr_str* temp1 = convert_float($1); expr_str* temp2 = convert_from_id($3, scope); $$ = num_expresion(temp1, temp2, '%');}
    
                 | '(' number_expression ')'                 {$$ = $2;}
                 | INT_VALUE                                 {$$ = convert_int($1);}
                 | FLOAT_VALUE                               {$$ = convert_float($1);}
                 ;    
                    
string_expression: ID CONCAT string_expression               {expr_str* temp = convert_from_id($1, scope); $$ = string_expresion(temp, $3, '#');}
                 | ID CONCAT ID                              {expr_str* temp1 = convert_from_id($1, scope); expr_str* temp2 = convert_from_id($3, scope); $$ = string_expresion(temp1, temp2, '#');}
                 | STRING_VALUE CONCAT string_expression     {expr_str* temp = convert_string($1); $$ = string_expresion(temp, $3, '#');}
                 | STRING_VALUE CONCAT ID                    {expr_str* temp1 = convert_string($1); expr_str* temp2 = convert_from_id($3, scope); $$ = string_expresion(temp1, temp2, '#');}
                 | CHAR_VALUE CONCAT string_expression       {expr_str* temp = convert_char($1); $$ = string_expresion(temp, $3, '#');}
                 | CHAR_VALUE CONCAT ID                      {expr_str* temp1 = convert_char($1); expr_str* temp2 = convert_from_id($3, scope); $$ = string_expresion(temp1, temp2, '#');}
                 | STRING_VALUE                              {$$ = convert_string($1);}
                 | CHAR_VALUE                                {$$ = convert_char($1);}
                 ;

bool_expression: ID AND bool_expression                      {expr_str* temp = convert_from_id($1, scope); $$ = bool_expresion(temp, $3, strdup("&"));}
               | ID AND ID                                   {expr_str* temp1 = convert_from_id($1, scope); expr_str* temp2 = convert_from_id($3, scope); $$ = bool_expresion(temp1, temp2, strdup("&"));}
               | ID OR bool_expression                       {expr_str* temp = convert_from_id($1, scope); $$ = bool_expresion(temp, $3, strdup("|"));}
               | ID OR ID                                    {expr_str* temp1 = convert_from_id($1, scope); expr_str* temp2 = convert_from_id($3, scope); $$ = bool_expresion(temp1, temp2, strdup("|"));}

               | BOOL_VALUE AND bool_expression              {expr_str* temp = convert_bool($1); $$ = bool_expresion(temp, $3, strdup("&"));}
               | BOOL_VALUE AND ID                           {expr_str* temp1 = convert_bool($1); expr_str* temp2 = convert_from_id($3, scope); $$ = bool_expresion(temp1, temp2, strdup("&"));}
               | BOOL_VALUE OR bool_expression               {expr_str* temp = convert_bool($1); $$ = bool_expresion(temp, $3, strdup("|"));}
               | BOOL_VALUE OR ID                            {expr_str* temp1 = convert_bool($1); expr_str* temp2 = convert_from_id($3, scope); $$ = bool_expresion(temp1, temp2, strdup("|"));}
               
               | '(' bool_expression ')'                     {$$ = $2;}
               | NOT bool_expression                         {$$ = bool_expresion($2, nullptr, strdup("!"));}
               | NOT ID                                      {expr_str* temp = convert_from_id($2, scope); $$ = bool_expresion(temp, nullptr, strdup("!"));}
               | number_expression REL_OP number_expression  {$$ = bool_expresion($1, $3, $2);}
               | ID REL_OP number_expression                 {expr_str* temp = convert_from_id($1, scope); $$ = bool_expresion(temp, $3, $2);}
               | ID REL_OP ID                                {expr_str* temp1 = convert_from_id($1, scope); expr_str* temp2 = convert_from_id($3, scope); $$ = bool_expresion(temp1, temp2, $2);}
               | BOOL_VALUE                                  {$$ = convert_bool($1);}
               ;

func_call: ID '(' param_call_list ')' {convert_function($1, scope);}
         | ID '(' ')'                 {convert_function($1, scope);}
         ;

param_call_list: param_call_list ',' expression
               | expression 
               ;

main_section: {strcpy(scope, strdup("main"));} MAIN '(' ')' '{' func_body '}' {strcpy(scope, strdup("global"));}
            ;

class_section: class_section class
             | class
             ;

class: CLASS ID {strcpy(scope, $2);} '{' class_body '}' {strcpy(scope, strdup("global"));}
     ;

class_body: attribute_section
          | method_section
          | attribute_section method_section
          ;

attribute_section: attribute_section attribute
                 | attribute
                 ;

attribute: ACC_MOD ID ':' TYPE ';'                   {expr_str *temp = create_empty_value($4); add_variable($2, $4, scope, false, temp);}
         | ACC_MOD ID ':' TYPE ASSIGN expression ';' {add_variable($2, $4, scope, false, $6);}
         | ACC_MOD ID '[' INT_VALUE ']' ':' TYPE ';' {add_vector($2, $7, scope, $4, false);}
         ;

method_section: constructor methods
              | constructor
              | methods
              ;

constructor: CONSTRUCTOR '(' param_list_method_opt ')' '{' func_body '}' {params.clear();}
           ;

methods: methods method
       | method
       ;

method: ACC_MOD ID {strcpy(prev_scope, scope); strcpy(scope, $2);} '(' param_list_method_opt ')' ':' TYPE {add_function($2, $8, prev_scope, params); params.clear();} '{' func_body '}' {strcpy(scope, prev_scope);}
      ;

param_list_method_opt: 
              | param_list_method
              ;

param_list_method: param_list_method ',' param
          | param
          ;
%%

void yyerror(const char * s) {
    printf("Error %d\n", yylineno);
}

int main(int argc, char **argv) {
    yydebug = 0;
    yyin = fopen(argv[1], "r");
    yyparse();
    return 0;
}
