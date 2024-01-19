#include "symbol_table.h"
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

ofstream fout("symbol_table.txt");

int var_count = 0;
int func_count = 0;
int vec_count = 0;
Variable variables[1000];
Function functions[1000];
Vector vectors[1000];

expr_str *convert_int(int value)
{
    expr_str *node = (expr_str *)malloc(sizeof(expr_str));
    node->type = INT;
    node->int_val = value;
    return node;
}

expr_str *convert_float(float value)
{
    expr_str *node = (expr_str *)malloc(sizeof(expr_str));
    node->type = FLOAT;
    node->float_val = value;
    return node;
}

expr_str *convert_string(char *value)
{
    expr_str *node = (expr_str *)malloc(sizeof(expr_str));
    node->type = STRING;
    node->string_val = (char *)malloc(strlen(value) * sizeof(char));
    strcpy(node->string_val, value);
    return node;
}

expr_str *convert_char(char value)
{
    expr_str *node = (expr_str *)malloc(sizeof(expr_str));
    node->type = CHAR;
    node->char_val = value;
    return node;
}

expr_str *convert_bool(bool value)
{
    expr_str *node = (expr_str *)malloc(sizeof(expr_str));
    node->type = BOOL;
    node->bool_val = value;
    return node;
}

expr_str *convert_from_id(char *name, char *scope)
{
    int index = find_variable(name, scope);

    if (index == -1)
    {
        index = find_variable(name, strdup("global"));
    }

    if (index != -1)
    {
        expr_str *node = (expr_str *)malloc(sizeof(expr_str));
        node->type = variables[index].type;
        switch (node->type)
        {
        case INT:
            node->int_val = atoi(variables[index].value);
            break;

        case FLOAT:
            node->float_val = atof(variables[index].value);
            break;

        case STRING:
            node->string_val = (char *)malloc(strlen(variables[index].value) * sizeof(char));
            strcpy(node->string_val, variables[index].value);
            break;

        case CHAR:
            node->char_val = variables[index].value[0];
            break;

        case BOOL:
            node->bool_val = variables[index].value[0] == 't' ? true : false;
            break;

        default:
            break;
        }
        return node;
    }
    else
    {
        printf("\033[0;31mError\033[0m: Variable %s not found in scope %s\n", name, scope);
        exit(1);
    }
}

expr_str *convert_function(char *name, char *scope)
{
    int index = find_function(name, scope);

    if (index == -1)
    {
        index = find_function(name, strdup("global"));
    }

    if (index != -1)
    {
        expr_str *node = (expr_str *)malloc(sizeof(expr_str));
        node->type = functions[index].type;

        switch (node->type)
        {
        case INT:
            node->int_val = 0;
            break;

        case FLOAT:
            node->float_val = 0;
            break;

        case STRING:
            node->string_val = (char *)malloc(sizeof(char));
            node->string_val[0] = '\0';
            break;

        case CHAR:
            node->char_val = '\0';
            break;

        case BOOL:
            node->bool_val = true;
            break;

        default:
            break;
        }

        return node;
    }
    else
    {
        printf("\033[0;31mError\033[0m: Function %s not found in scope %s\n", name, scope);
        exit(1);
    }
}

expr_str *num_expresion(expr_str *exp1, expr_str *exp2, char op)
{
    if (exp1->type != exp2->type)
    {
        printf("\033[0;31mError\033[0m: Type mismatch\n");
        exit(1);
    }

    if (exp1->type != INT && exp1->type != FLOAT)
    {
        printf("\033[0;31mError\033[0m: Type mismatch\n");
        exit(1);
    }

    expr_str *node = (expr_str *)malloc(sizeof(expr_str));
    node->type = exp1->type;

    switch (op)
    {
    case '+':
        if (exp1->type == INT)
        {
            node->int_val = exp1->int_val + exp2->int_val;
            return node;
        }
        else if (exp1->type == FLOAT)
        {
            node->float_val = exp1->float_val + exp2->float_val;
            return node;
        }
        break;

    case '-':
        if (exp1->type == INT)
        {
            node->int_val = exp1->int_val - exp2->int_val;
            return node;
        }
        else if (exp1->type == FLOAT)
        {
            node->float_val = exp1->float_val - exp2->float_val;
            return node;
        }
        break;

    case '*':
        if (exp1->type == INT)
        {
            node->int_val = exp1->int_val * exp2->int_val;
            return node;
        }
        else if (exp1->type == FLOAT)
        {
            node->float_val = exp1->float_val * exp2->float_val;
            return node;
        }
        break;

    case '/':
        if (exp1->type == INT)
        {
            if (exp2->int_val == 0)
            {
                printf("\033[0;31mError\033[0m: Division by 0\n");
                exit(1);
            }
            node->int_val = exp1->int_val / exp2->int_val;
            return node;
        }
        else if (exp1->type == FLOAT)
        {
            if (exp2->float_val == 0)
            {
                printf("\033[0;31mError\033[0m: Division by 0\n");
                exit(1);
            }
            node->float_val = exp1->float_val / exp2->float_val;
            return node;
        }
        break;

    case '%':
        if (exp1->type == INT)
        {
            if (exp2->int_val == 0)
            {
                printf("\033[0;31mError\033[0m: Division by 0\n");
                exit(1);
            }
            node->int_val = exp1->int_val % exp2->int_val;
            return node;
        }
        else if (exp1->type == FLOAT)
        {
            printf("\033[0;31mError\033[0m: Modulo operation on float\n");
            exit(1);
        }
        break;

    default:
        break;
    }
    return nullptr;
}

expr_str *bool_expresion(expr_str *exp1, expr_str *exp2, char *op)
{
    if (exp1->type != exp2->type && exp2 != nullptr)
    {
        printf("\033[0;31mError\033[0m: Type mismatch\n");
        exit(1);
    }

    if (exp1->type == INT || exp1->type == FLOAT)
    {
        expr_str *node = (expr_str *)malloc(sizeof(expr_str));
        node->type = BOOL;

        if (strcmp(op, "<=") == 0)
        {
            if (exp1->type == INT)
            {
                node->bool_val = exp1->int_val <= exp2->int_val;
                return node;
            }
            else if (exp1->type == FLOAT)
            {
                node->bool_val = exp1->float_val <= exp2->float_val;
                return node;
            }
        }
        if (strcmp(op, ">=") == 0)
        {
            if (exp1->type == INT)
            {
                node->bool_val = exp1->int_val >= exp2->int_val;
                return node;
            }
            else if (exp1->type == FLOAT)
            {
                node->bool_val = exp1->float_val >= exp2->float_val;
                return node;
            }
        }
        if (strcmp(op, "<") == 0)
        {
            if (exp1->type == INT)
            {
                node->bool_val = exp1->int_val < exp2->int_val;
                return node;
            }
            else if (exp1->type == FLOAT)
            {
                node->bool_val = exp1->float_val < exp2->float_val;
                return node;
            }
        }
        if (strcmp(op, ">") == 0)
        {
            if (exp1->type == INT)
            {
                node->bool_val = exp1->int_val > exp2->int_val;
                return node;
            }
            else if (exp1->type == FLOAT)
            {
                node->bool_val = exp1->float_val > exp2->float_val;
                return node;
            }
        }
        if (strcmp(op, "==") == 0)
        {
            if (exp1->type == INT)
            {
                node->bool_val = exp1->int_val == exp2->int_val;
                return node;
            }
            else if (exp1->type == FLOAT)
            {
                node->bool_val = exp1->float_val == exp2->float_val;
                return node;
            }
        }
        if (strcmp(op, "!=") == 0)
        {
            if (exp1->type == INT)
            {
                node->bool_val = exp1->int_val != exp2->int_val;
                return node;
            }
            else if (exp1->type == FLOAT)
            {
                node->bool_val = exp1->float_val != exp2->float_val;
                return node;
            }
        }
    }
    else if (exp1->type == BOOL)
    {
        expr_str *node = (expr_str *)malloc(sizeof(expr_str));
        node->type = BOOL;
        if (strcmp(op, "!") == 0 && exp2 == nullptr)
        {
            node->bool_val = !exp1->bool_val;
            return node;
        }
        else if (strcmp(op, "&") == 0 && exp2 != nullptr)
        {
            node->bool_val = exp1->bool_val && exp2->bool_val;
            return node;
        }
        else if (strcmp(op, "|") == 0 && exp2 != nullptr)
        {
            node->bool_val = exp1->bool_val || exp2->bool_val;
            return node;
        }
    }
    else
    {
        printf("\033[0;31mError\033[0m: Type mismatch\n");
        exit(1);
    }
    return nullptr;
}

expr_str *string_expresion(expr_str *exp1, expr_str *exp2, char op)
{
    if (exp1->type != STRING || exp2->type != STRING || exp1->type != CHAR || exp2->type != CHAR)
    {
        printf("\033[0;31mError\033[0m: Type mismatch\n");
        exit(1);
    }

    expr_str *node = (expr_str *)malloc(sizeof(expr_str));
    node->type = STRING;

    if (op == '#')
    {
        if (exp1->type == STRING && exp2->type == STRING)
        {
            node->string_val = (char *)malloc((strlen(exp1->string_val) + strlen(exp2->string_val)) * sizeof(char));
            strcpy(node->string_val, exp1->string_val);
            strcat(node->string_val, exp2->string_val);
            return node;
        }
        else if (exp1->type == STRING && exp2->type == CHAR)
        {
            node->string_val = (char *)malloc((strlen(exp1->string_val) + 1) * sizeof(char));
            strcpy(node->string_val, exp1->string_val);
            node->string_val[strlen(exp1->string_val)] = exp2->char_val;
            return node;
        }
        else if (exp1->type == CHAR && exp2->type == STRING)
        {
            node->string_val = (char *)malloc((strlen(exp2->string_val) + 1) * sizeof(char));
            node->string_val[0] = exp1->char_val;
            strcpy(node->string_val + 1, exp2->string_val);
            return node;
        }
        else if (exp1->type == CHAR && exp2->type == CHAR)
        {
            node->string_val = (char *)malloc(2 * sizeof(char));
            node->string_val[0] = exp1->char_val;
            node->string_val[1] = exp2->char_val;
            return node;
        }
    }
    return nullptr;
}

int find_variable(char *name, char *scope)
{
    for (int i = 0; i < var_count; i++)
    {
        if (strcmp(variables[i].name, name) == 0 && strcmp(variables[i].scope, scope) == 0)
        {
            return i;
        }
    }
    return -1;
}

int find_function(char *name, char *scope)
{
    for (int i = 0; i < func_count; i++)
    {
        if (strcmp(functions[i].name, name) == 0 && strcmp(functions[i].scope, scope) == 0)
        {
            return i;
        }
    }
    return -1;
}

int find_vector(char *name, char *scope)
{
    for (int i = 0; i < vec_count; i++)
    {
        if (strcmp(vectors[i].name, name) == 0 && strcmp(vectors[i].scope, scope) == 0)
        {
            return i;
        }
    }
    return -1;
}

void add_variable(char *name, char *type, char *scope, bool is_const, expr_str *value)
{
    if (find_variable(name, scope) == -1 && find_function(name, scope) == -1 && find_vector(name, scope) == -1)
    {
        if (strcmp(type, "integer") == 0)
        {
            if (value->type != INT)
            {
                printf("\033[0;31mError\033[0m: Type mismatch\n");
                exit(1);
            }
        }
        else if (strcmp(type, "float") == 0)
        {
            if (value->type != FLOAT)
            {
                printf("\033[0;31mError\033[0m: Type mismatch\n");
                exit(1);
            }
        }
        else if (strcmp(type, "string") == 0)
        {
            if (value->type != STRING)
            {
                printf("\033[0;31mError\033[0m: Type mismatch\n");
                exit(1);
            }
        }
        else if (strcmp(type, "char") == 0)
        {
            if (value->type != CHAR)
            {
                printf("\033[0;31mError\033[0m: Type mismatch\n");
                exit(1);
            }
        }
        else if (strcmp(type, "bool") == 0)
        {
            if (value->type != BOOL)
            {
                printf("\033[0;31mError\033[0m: Type mismatch\n");
                exit(1);
            }
        }
        else if (strcmp(type, "void") == 0)
        {
            printf("\033[0;31mError\033[0m: Variable %s cannot be void\n", name);
        }

        variables[var_count].name = (char *)malloc(strlen(name) * sizeof(char));
        strcpy(variables[var_count].name, name);

        if (value == nullptr)
        {
            value = create_empty_value(type);
        }

        if (strcmp(type, "integer") == 0)
        {
            variables[var_count].type = INT;
            variables[var_count].value = (char *)malloc(sizeof(int));
            sprintf(variables[var_count].value, "%d", value->int_val);
        }
        else if (strcmp(type, "float") == 0)
        {
            variables[var_count].type = FLOAT;
            variables[var_count].value = (char *)malloc(sizeof(float));
            sprintf(variables[var_count].value, "%f", value->float_val);
        }
        else if (strcmp(type, "string") == 0)
        {
            variables[var_count].type = STRING;
            variables[var_count].value = (char *)malloc(strlen(value->string_val) * sizeof(char));
            strcpy(variables[var_count].value, value->string_val);
        }
        else if (strcmp(type, "char") == 0)
        {
            variables[var_count].type = CHAR;
            variables[var_count].value = (char *)malloc(sizeof(char));
            variables[var_count].value[0] = value->char_val;
        }
        else if (strcmp(type, "bool") == 0)
        {
            variables[var_count].type = BOOL;
            variables[var_count].value = (char *)malloc(sizeof(char));
            variables[var_count].value[0] = value->bool_val ? 't' : 'f';
        }
        else if (strcmp(type, "void") == 0)
        {
            printf("\033[0;31mError\033[0m: Variable %s cannot be void\n", name);
        }

        variables[var_count].scope = (char *)malloc(strlen(scope) * sizeof(char));
        strcpy(variables[var_count].scope, scope);

        variables[var_count].is_const = is_const;

        var_count++;

        fout << "Scope: " << scope << " Name: " << name << " Type: " << type << "\n";
    }
    else
    {
        printf("\033[0;31mError\033[0m: Variable %s already declared in scope %s or global\n", name, scope);
        exit(1);
    }
    
}

void add_vector(char *name, char *type, char *scope, int size, bool is_const)
{
    if (is_const)
    {
        printf("\033[0;31mError\033[0m: Vector %s cannot be const\n", name);
    }

    if (size <= 0)
    {
        printf("\033[0;31mError\033[0m: Vector %s cannot have size %d\n", name, size);
    }

    if (find_variable(name, scope) == -1 && find_function(name, scope) == -1 && find_vector(name, scope) == -1)
    {
        vectors[vec_count].name = (char *)malloc(strlen(name) * sizeof(char));
        strcpy(vectors[vec_count].name, name);

        if (strcmp(type, "integer") == 0)
        {
            vectors[vec_count].type = INT;
        }
        else if (strcmp(type, "float") == 0)
        {
            vectors[vec_count].type = FLOAT;
        }
        else if (strcmp(type, "string") == 0)
        {
            vectors[vec_count].type = STRING;
        }
        else if (strcmp(type, "char") == 0)
        {
            vectors[vec_count].type = CHAR;
        }
        else if (strcmp(type, "bool") == 0)
        {
            vectors[vec_count].type = BOOL;
        }
        else if (strcmp(type, "void") == 0)
        {
            printf("\033[0;31mError\033[0m: Vector %s cannot be void\n", name);
        }

        vectors[vec_count].scope = (char *)malloc(strlen(scope) * sizeof(char));
        strcpy(vectors[vec_count].scope, scope);

        vectors[vec_count].size = size;

        vectors[vec_count].values = (char **)malloc(size * sizeof(char *));

        vec_count++;

        fout << "Scope: " << scope << " Name: " << name << " Type: " << type << " Size: " << size << "\n";
    }
}

void add_function(char *name, char *type, char *scope, std::vector<Variable *> parameters)
{
    if (find_variable(name, scope) == -1 && find_function(name, scope) == -1 && find_vector(name, scope) == -1)
    {
        functions[func_count].name = (char *)malloc(strlen(name) * sizeof(char));
        strcpy(functions[func_count].name, name);

        if (strcmp(type, "integer") == 0)
        {
            functions[func_count].type = INT;
        }
        else if (strcmp(type, "float") == 0)
        {
            functions[func_count].type = FLOAT;
        }
        else if (strcmp(type, "string") == 0)
        {
            functions[func_count].type = STRING;
        }
        else if (strcmp(type, "char") == 0)
        {
            functions[func_count].type = CHAR;
        }
        else if (strcmp(type, "bool") == 0)
        {
            functions[func_count].type = BOOL;
        }
        else if (strcmp(type, "void") == 0)
        {
            functions[func_count].type = VOID;
        }

        functions[func_count].scope = (char *)malloc(strlen(scope) * sizeof(char));
        strcpy(functions[func_count].scope, scope);

        functions[func_count].parameters = parameters;


        func_count++;

        fout << "Scope: " << scope << " Name: " << name << " Type: " << type << " Parameter types: ";
        for (auto p : parameters)
        {
            switch (p->type)
            {
            case INT:
                fout << "integer ";
                break;
            
            case FLOAT:
                fout << "float ";
                break;

            case STRING:
                fout << "string ";
                break;

            case CHAR:
                fout << "char ";
                break;

            case BOOL:
                fout << "bool ";
                break;

            default:
                break;
            }
        }
        fout << "\n";
    }
}

expr_str *create_empty_value(char * type)
{
    expr_str *empty_value = (expr_str *)malloc(sizeof(expr_str));

    if (strcmp(type, "integer") == 0)
    {
        empty_value->type = INT;
        empty_value->int_val = 0;
    }
    else if (strcmp(type, "float") == 0)
    {
        empty_value->type = FLOAT;
        empty_value->float_val = 0;
    }
    else if (strcmp(type, "string") == 0)
    {
        empty_value->type = STRING;
        empty_value->string_val = (char *)malloc(sizeof(char));
        empty_value->string_val[0] = '\0';
    }
    else if (strcmp(type, "char") == 0)
    {
        empty_value->type = CHAR;
        empty_value->char_val = '\0';
    }
    else if (strcmp(type, "bool") == 0)
    {
        empty_value->type = BOOL;
        empty_value->bool_val = true;
    }
    else if (strcmp(type, "void") == 0)
    {
        printf("\033[0;31mError\033[0m: Variable cannot be void\n");
        exit(1);
    }

    return empty_value;
}

Variable *create_param(char *name, char *type, char *scope)
{
    Variable *param = (Variable *)malloc(sizeof(Variable));
    param->name = (char *)malloc(strlen(name) * sizeof(char));
    strcpy(param->name, name);

    if (strcmp(type, "integer") == 0)
    {
        param->type = INT;
        param->value = (char *)malloc(sizeof(int));
        strcpy(param->value, "0");
    }
    else if (strcmp(type, "float") == 0)
    {
        param->type = FLOAT;
        param->value = (char *)malloc(sizeof(float));
        strcpy(param->value, "0.0");
    }
    else if (strcmp(type, "string") == 0)
    {
        param->type = STRING;
        param->value = (char *)malloc(sizeof(char));
        strcpy(param->value, "");
    }
    else if (strcmp(type, "char") == 0)
    {
        param->type = CHAR;
        param->value = (char *)malloc(sizeof(char));
        strcpy(param->value, "");
    }
    else if (strcmp(type, "bool") == 0)
    {
        param->type = BOOL;
        param->value = (char *)malloc(sizeof(char));
        strcpy(param->value, "f");
    }
    else if (strcmp(type, "void") == 0)
    {
        printf("\033[0;31mError\033[0m: Parameter %s of function %s cannot be void\n", name, scope);
        exit(1);
    }

    param->is_const = false;

    param->scope = (char *)malloc(strlen(scope) * sizeof(char));
    strcpy(param->scope, scope);

    expr_str *empty_value = create_empty_value(type);

    add_variable(param->name, type, param->scope, false, empty_value);

    return param;
}

void update_variable(char *name, char *scope, expr_str *value)
{
    int index = find_variable(name, scope);

    if (index == -1)
    {
        index = find_variable(name, strdup("global"));
    }

    if (index != -1)
    {
        if (variables[index].is_const)
        {
            printf("\033[0;31mError\033[0m: Variable %s is const\n", name);
            exit(1);
        }

        if (value->type != variables[index].type)
        {
            printf("\033[0;31mError\033[0m: Type mismatch\n");
            exit(1);
        }

        switch (value->type)
        {
        case INT:
            variables[index].value = (char *)realloc(variables[index].value, sizeof(int));
            sprintf(variables[index].value, "%d", value->int_val);
            break;

        case FLOAT:
            variables[index].value = (char *)realloc(variables[index].value, sizeof(float));
            sprintf(variables[index].value, "%f", value->float_val);
            break;

        case STRING:
            variables[index].value = (char *)realloc(variables[index].value, strlen(value->string_val) * sizeof(char));
            strcpy(variables[index].value, value->string_val);
            break;

        case CHAR:
            variables[index].value = (char *)realloc(variables[index].value, sizeof(char));
            variables[index].value[0] = value->char_val;
            break;

        case BOOL:
            variables[index].value = (char *)realloc(variables[index].value, sizeof(char));
            variables[index].value[0] = value->bool_val ? 't' : 'f';
            break;

        default:
            break;
        }
    }
    else
    {
        printf("\033[0;31mError\033[0m: Variable %s not found in scope %s\n", name, scope);
        exit(1);
    }
}

void update_vector(char *name, char *scope, expr_str *pos, expr_str *value)
{
    int index = find_vector(name, scope);

    if (index == -1)
    {
        index = find_vector(name, strdup("global"));
    }

    if (index != -1)
    {
        if (pos->type != INT)
        {
            printf("\033[0;31mError\033[0m: Vector %s index must be integer\n", name);
            exit(1);
        }

        if (value->type != vectors[index].type)
        {
            printf("\033[0;31mError\033[0m: Type mismatch\n");
            exit(1);
        }

        if (pos->int_val < 0 || pos->int_val >= vectors[index].size)
        {
            printf("\033[0;31mError\033[0m: Vector %s index out of bounds\n", name);
            exit(1);
        }

        switch (value->type)
        {
        case INT:
            vectors[index].values[pos->int_val] = (char *)realloc(vectors[index].values[pos->int_val], sizeof(int));
            sprintf(vectors[index].values[pos->int_val], "%d", value->int_val);
            break;

        case FLOAT:
            vectors[index].values[pos->int_val] = (char *)realloc(vectors[index].values[pos->int_val], sizeof(float));
            sprintf(vectors[index].values[pos->int_val], "%f", value->float_val);
            break;

        case STRING:
            vectors[index].values[pos->int_val] = (char *)realloc(vectors[index].values[pos->int_val], strlen(value->string_val) * sizeof(char));
            strcpy(vectors[index].values[pos->int_val], value->string_val);
            break;

        case CHAR:
            vectors[index].values[pos->int_val] = (char *)realloc(vectors[index].values[pos->int_val], sizeof(char));
            vectors[index].values[pos->int_val][0] = value->char_val;
            break;

        case BOOL:
            vectors[index].values[pos->int_val] = (char *)realloc(vectors[index].values[pos->int_val], sizeof(char));
            vectors[index].values[pos->int_val][0] = value->bool_val ? 't' : 'f';
            break;

        default:
            break;
        }
    }
    else
    {
        printf("\033[0;31mError\033[0m: Vector %s not found in scope %s\n", name, scope);
        exit(1);
    }
}

const char *type_of_def(char *name, char *scope)
{
    if (find_variable(name, strdup("global")) != -1 || find_variable(name, scope) != -1)
    {
        int index = find_variable(name, scope);
        if (index == -1)
        {
            index = find_variable(name, strdup("global"));
        }

        switch (variables[index].type)
        {
        case INT:
            return "integer";
            break;

        case FLOAT:
            return "float";
            break;

        case STRING:
            return "string";
            break;

        case CHAR:
            return "char";
            break;

        case BOOL:
            return "bool";
            break;      

        default:    
            return "undefined";
            break;
        }
    }
    else if (find_function(name, strdup("global")) != -1 || find_function(name, scope) != -1)
    {
        int index = find_function(name, scope);
        if (index == -1)
        {
            index = find_function(name, strdup("global"));
        }

        switch (functions[index].type)
        {
        case INT:
            return "integer";
            break;

        case FLOAT:
            return "float";
            break;

        case STRING:
            return "string";
            break;

        case CHAR:
            return "char";
            break;

        case BOOL:
            return "bool";
            break;

        case VOID:
            return "void";
            break;      

        default:    
            return "undefined";
            break;
        }
    }
    else if (find_vector(name, strdup("global")) != -1 || find_vector(name, scope) != -1)
    {
        int index = find_vector(name, scope);
        if (index == -1)
        {
            index = find_vector(name, strdup("global"));
        }

        switch (vectors[index].type)
        {
        case INT:
            return "integer";
            break;

        case FLOAT:
            return "float";
            break;

        case STRING:
            return "string";
            break;

        case CHAR:
            return "char";
            break;

        case BOOL:
            return "bool";
            break;      

        default:    
            return "undefined";
            break;
        }
    }
    else
    {
        return "undefined";
    }
}