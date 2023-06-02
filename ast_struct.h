#ifndef AST_STRUCT_H_INCLUDED
#define AST_STRUCT_H_INCLUDED

typedef enum {
    AST_VOID,
    AST_INTEGER,
    AST_BINARY,
    AST_UNARY,
    AST_FUNCTION,
    AST_FNCALL,
    AST_VARIABLE,
    AST_CONDITION,
    AST_LOOP,
    AST_DECLARATION,
    AST_ASSIGNMENT,
    AST_COMPOUND_STATEMENT,
    AST_RETURN
} ast_node_type_e;

typedef enum{
    OP_GREATER_THAN,
    OP_LESS_THAN,
    OP_GREATER_THAN_EQUAL,
    OP_LESS_THAN_EQUAL,
    OP_EQUALITY,
    OP_INEQUALITY,
    OP_OR,
    OP_AND,
    OP_DIVISION,
    OP_SUBSTRACTION,
    OP_MULTIPLICATION,
    OP_ADDITION
}ast_binary_e;

typedef enum{
    OP_INDIRECTION, // (*)
    OP_ADDRESS, // &
    OP_PLUS, // +
    OP_NEGATION, // -
    OP_INCREMENT, // ++
    OP_DECREMENT, // --
    OP_COMPLEMENT, //
    OP_LOGICAL_NEGATION // !
}ast_unary_e;

typedef struct ast_list_t{

}ast_list_t;

typedef struct ast_t {
     ast_node_type_e type;

     // variable structure to represent a variable
     union {
         long integer;
         struct {
         char *name;
         int type;
     } var;

     // binary structure
     struct {
         ast_binary_e op;
         struct ast_t *left;
         struct ast_t *right;
     } binary;

     // unary structure
     struct {
         char op;
         struct ast_t *operand;
     } unary;

     // call structure
     struct {
         char *name;
         struct ast_list_t *args;
     } call;

     // function structure
     struct {
         char *name;
         int return_type;
         struct ast_list_t *params;
         struct ast_list_t *stmts;
     } function;

     // statement compound structure
     struct {
        struct ast_list_t *stmts;
     } compound_stmt;

     // assignment structure
     struct {
         struct ast_t *lvalue;
         struct ast_t *rvalue;
     } assignment;

     // declaration structure
     struct {
         struct ast_t *lvalue;
         struct ast_t *rvalue;
     } declaration;

     // branch structure
     struct {
         struct ast_t *condition;
         struct ast_t *valid;
         struct ast_t *invalid;
     }branch;

     // loop structure
     struct {
         struct ast_t *condition;
         struct ast_t *stmt;
     }loop;

     // return structure
     struct {
         struct ast_t *expr;
     } ret;


     };
} ast_t;

#endif // AST_STRUCT_H_INCLUDED
