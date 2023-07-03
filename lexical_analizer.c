#include "lexical_analizer.h"
#include "syntax_analyser.h"

#include "ast_struct.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>


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


ast_t *analyse_function(buffer_t *buffer){

    ast_t *ast =  NULL;

    // open file and give it to the buffer
    // get the lexeme using get_alphanum
    // if lexeme  is not function terminate the program
    char *function_name = lexer_getalphanum(buffer); // main

    ast_list_t *stmts_list = NULL;

    // analyze function name

    ast_list_t *list_of_params = analyse_parameters(buffer);

    int returned_type = analyse_returned_type(buffer);

        // invalid returned type encounter
    if(returned_type == -1){
        exit(EXIT_FAILURE);
    }

    ast = ast_new_function(function_name, returned_type,list_of_params, stmts_list);

    return ast;
}
/*
ast_list_t *analyse_parameters(buffer_t *buffer){

    ast_list_t *parameter_list_node = NULL;

    char next_char = buf_getchar_after_blank(buffer);

    if(next_char != '('){
        fprintf(stderr, "Error missing (", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char *parameter_type_lexeme, *parameter_name, *next_lexeme;

    int parameter_type = 0;

    next_lexeme = lexer_getalphanum(buffer);

    while(next_lexeme[0] != ')' && next_lexeme[0] != '\0'){

        int result = strcmp(next_lexeme, "entier");

        if( result != 0){
            fprintf(stderr, "Error missing type %s", next_lexeme);
            exit(EXIT_FAILURE);
        }

        parameter_type_lexeme = next_lexeme;

        next_lexeme = lexer_getalphanum(buffer); // get parameter name
        // check the existence of parameter name in the symbol table
        // does not exist add it in the symbol table
        // create the ast list of type parameter

        parameter_type = 1;

        parameter_name = next_lexeme;

        ast_t *variable_node = ast_new_variable(parameter_name, parameter_type);

        parameter_list_node = ast_list_add(parameter_list_node, variable_node);

        next_lexeme = lexer_getalphanum(buffer);
    }

    return parameter_list_node;

}*/

ast_list_t *analyse_parameters(buffer_t *buffer){

    ast_list_t *params_list = NULL;

    ast_t *ast_parameter_node = NULL;

    char next_char = buf_getchar_after_blank(buffer);

    if(next_char != '('){
        fprintf(stderr, "missing '(' after function name", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char *next_lexeme;

    bool result;

    while(next_char != ')'){

        next_lexeme = lexer_getalphanum(buffer);

        result = is_allowed_type(next_lexeme);

        if(result == true){

            int parameter_type = lexeme_to_type(next_lexeme);

            next_lexeme = lexer_getalphanum(buffer);

            if(is_lexeme_keyword(next_lexeme) == true){
                fprintf(stderr, "\n Error: %s is a keyword and cannot be used as param name", next_lexeme);
                exit(EXIT_FAILURE);
            }

            result = is_lexeme_digit(next_lexeme);

            if(result == true){
                fprintf(stderr, "\n Error: %s is number and cannot be used as parameter name", next_lexeme);
                exit(EXIT_FAILURE);
            }

            char *parameter_name = next_lexeme;

            ast_parameter_node = ast_new_variable(parameter_name, parameter_type);

            params_list = ast_list_add(params_list, ast_parameter_node);

            next_char = buf_getchar(buffer);
        }
        else{
            fprintf(stderr, "\n Error: invalid parameter type %d", result);
            exit(EXIT_FAILURE);
        }
    }
    return params_list;

}

ast_t *analyse_function_body(buffer_t *buffer){


}

int analyse_returned_type(buffer_t *buffer){

    //this should be fixed
    buffer->it -= 1;

    char semil_colon = buf_getchar_after_blank(buffer);

    if(semil_colon != ':'){
         fprintf(stderr, "Error missing ':' symbol");
         exit(EXIT_FAILURE);
    }

    char *returned_type = lexer_getalphanum(buffer);

    int type_number;

    if(strcmp(returned_type, "rien") == 0){
        type_number = 1;
    }else if(strcmp(returned_type, "entier") == 0){
        type_number = 2;
    }else{
        type_number = -1;
        fprintf(stderr, "invalid type %s", returned_type);
    }

    return type_number;

}

int parser(buffer_t *buffer){

    char *lexeme = lexer_getalphanum(buffer);

    if(!strcmp(lexeme, "fonction"))
        return 1;

    // add the lexeme to the symbol table before calling analyse_function

    ast_t *function_tree = analyse_function(buffer);

    if(function_tree == NULL)
        return 1;

    return 0;
}
