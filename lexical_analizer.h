#ifndef LEXICAL_ANALIZER_H_INCLUDED
#define LEXICAL_ANALIZER_H_INCLUDED
#include "ast_struct.h"
#include "buffer.h"

ast_t *ast_new_integer (long val);
ast_t *ast_new_variable (char *name, int type);
ast_t *ast_new_binary (ast_binary_e op, ast_t *left, ast_t *right);
ast_t *ast_new_unary (ast_unary_e op, ast_t *operand);
ast_t *ast_new_function (char *name, int return_type, ast_list_t *params, ast_list_t *stmts);
ast_t *ast_new_fncall (char *name, ast_list_t *args);
ast_t *ast_new_comp_stmt (ast_list_t *stmts);
ast_t *ast_new_assignment (ast_t *lvalue, ast_t *rvalue);
ast_t *ast_new_declaration (ast_t *lvalue, ast_t *rvalue);
ast_t *ast_new_condition (ast_t *condition, ast_t *valid, ast_t *invalid);
ast_t *ast_new_loop (ast_t *condition, ast_t *stmt);
ast_t *ast_new_return (ast_t *expr);
ast_list_t *ast_list_new_node (ast_t *elem);
ast_list_t *ast_list_add (ast_list_t **list, ast_t *elem);



ast_t *analyse_function(buffer_t *buffer);

ast_list_t  *analyse_parameters(buffer_t *buffer);

ast_t *analyse_function_body(buffer_t *buffer);

ast_t *analyse_returned_type(buffer_t *buffer);

int parser(buffer_t *buffer);


#endif // LEXICAL_ANALIZER_H_INCLUDED
