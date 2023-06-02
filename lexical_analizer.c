#include "lexical_analizer.h"
#include "ast_struct.h"
#include <stdio.h>

ast_t *ast_new_integer(long val){

    ast_t *ast = malloc(sizeof(ast_t));

    ast->integer = val;

    return ast;
}

ast_t *ast_new_variable(char *name, int type){
    ast_t *ast = malloc(sizeof(ast_t));

    ast->var.name = name;
    ast->var.type = type;

    return ast;
}

ast_t *ast_new_binary(ast_binary_e op, ast_t *left, ast_t *right){

     ast_t *ast = malloc(sizeof(ast_t));

     ast->binary.left = left;
     ast->binary.right = right;
     ast->binary.op = op;

     return ast;
}
ast_t *ast_new_unary (ast_unary_e op, ast_t *operand){

    ast_t *ast = malloc(sizeof(ast_t));

    ast->unary.op = op;
    ast->unary.operand = operand;

    return ast;
}

ast_t *ast_new_function (char *name, int return_type, ast_list_t *params, ast_list_t *stmts){
    ast_t *ast = malloc(sizeof(ast_t));

    ast->function.name = name;
    ast->function.params = params;
    ast->function.stmts = stmts;

    return ast;
}
ast_t *ast_new_fncall (char *name, ast_list_t *args){
     ast_t *ast = malloc(sizeof(ast_t));
     ast->call.name = name;
     ast->call.args = args;

     return ast;
}
ast_t *ast_new_comp_stmt (ast_list_t *stmts){
     ast_t *ast = malloc(sizeof(ast_t));

     ast->compound_stmt.stmts = stmts;
     return ast;
}
ast_t *ast_new_assignment (ast_t *lvalue, ast_t *rvalue){
     ast_t *ast = malloc(sizeof(ast_t));

     ast->assignment.lvalue = lvalue;
     ast->assignment.rvalue = rvalue;
     return ast;
}
ast_t *ast_new_declaration (ast_t *lvalue, ast_t *rvalue){
    ast_t *ast = malloc(sizeof(ast_t));

    ast->declaration.lvalue = lvalue;
    ast->declaration.rvalue = rvalue;
    return ast;
}
ast_t *ast_new_condition (ast_t *condition, ast_t *valid, ast_t *invalid){
     ast_t *ast = malloc(sizeof(ast_t));

     ast->branch.condition = condition;
     ast->branch.valid = valid;
     ast->branch.invalid = invalid;

     return ast;
}

ast_t *ast_new_loop (ast_t *condition, ast_t *stmt){
     ast_t *ast = malloc(sizeof(ast_t));

     ast->loop.condition = condition;
     ast->loop.stmt = stmt;

     return ast;
}
ast_t *ast_new_return (ast_t *expr){
     ast_t *ast = malloc(sizeof(ast_t));

     ast->ret.expr = expr;

     return ast;
}
ast_list_t *ast_list_new_node(ast_t *elem){
    ast_list_t *node = malloc(sizeof(ast_list_t));

    node->data = elem;
    node->next = NULL;

    return node;
}
ast_list_t *ast_list_add (ast_list_t **list, ast_t *elem){

     ast_list_t *node = malloc(sizeof(ast_list_t));
     node->data = elem;
     node->next = list;
     return node;
}
