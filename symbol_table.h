#include <vector>
#include <list>

enum Type {
    INT,
    FLOAT,
    STRING,
    CHAR,
    BOOL,
    VOID
};

struct expr_str {
    Type type;
    
    int int_val;
    float float_val;
    char *string_val;
    char char_val;
    bool bool_val;
};

struct Variable {
    char *name;
    Type type;
    char *value;
    char *scope;
    bool is_const;
};

struct Function {
    char *name;
    Type type;
    char *scope;
    std::vector<Variable *> parameters;
};

struct Vector {
    char *name;
    Type type;
    char *scope;
    int size;
    char **values;
};

expr_str* convert_int(int);
expr_str* convert_float(float);
expr_str* convert_string(char *);
expr_str* convert_char(char);
expr_str* convert_bool(bool);
expr_str* convert_from_id(char *, char *);
expr_str* convert_function(char *, char *);
expr_str* create_empty_value(char *);

expr_str* num_expresion(expr_str *, expr_str *, char);
expr_str* bool_expresion(expr_str *, expr_str *, char *);
expr_str* string_expresion(expr_str *, expr_str *, char);

int find_variable(char *, char *);
int find_function(char *, char *);
int find_vector(char *, char *);

void add_variable(char *, char *, char *, bool, expr_str *);
void add_function(char *, char *, char *, std::vector<Variable *>);
void add_vector(char *, char *, char *, int, bool);

void update_variable(char *, char *, expr_str *);
void update_vector(char *, char *, expr_str *, expr_str *);

Variable* create_param(char *, char *, char *);

const char* type_of_def(char *, char *);
//void add_parameter(char *, char *, char *);