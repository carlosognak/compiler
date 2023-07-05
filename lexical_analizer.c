#include "lexical_analizer.h"
#include "syntax_analyser.h"

#include "ast_struct.h"
#include "utils.h"

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>



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

    // analyze function name must be done here

    ast_list_t *list_of_params = analyse_parameters(buffer);

    int returned_type = analyse_returned_type(buffer);

        // invalid returned type encounter
    if(returned_type == -1){
        exit(EXIT_FAILURE);
    }

    ast = ast_new_function(function_name, returned_type, list_of_params, stmts_list);

    return ast;
}
ast_list_t *analyse_parameters(buffer_t *buffer){

    ast_list_t *params_list = NULL;

    ast_t *ast_parameter_node = NULL;

    char next_char = buf_getchar_after_blank(buffer);

    if(next_char != '('){
        fprintf(stderr, "missing '(' after function name");
        exit(EXIT_FAILURE);
    }

    bool result;

    while(next_char != ')'){

        char* next_lexeme = lexer_getalphanum(buffer);

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

            ast_parameter_node = ast_new_variable(next_lexeme, parameter_type);

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

    char next_symbol = buf_getchar_after_blank(buffer);

    ast_t *expression_node = NULL;

    if(next_symbol != '{'){
        fprintf(stderr, "Error missing '{' symbol");
        exit(EXIT_FAILURE);
    }

    ast_t *ast_function_body_node = NULL;

    char* nextLexeme;

    while(next_symbol != '}' && buf_eof(buffer) == false){

        nextLexeme = lexer_getalphanum(buffer);

        if(is_lexeme_keyword(nextLexeme) == false){
            fprintf(stderr, "Error: %s unknown keyword.", nextLexeme);
            exit(EXIT_FAILURE);
        }

        if(is_lexeme_type_entier(nextLexeme)){

            int type = lexeme_to_type(nextLexeme);
            // get the variable name
            nextLexeme = lexer_getalphanum(buffer);

            ast_t *lvalue = ast_new_variable(nextLexeme, type);

            next_symbol = buf_getchar_after_blank(buffer);

            if(next_symbol != '=' && next_symbol != ';'){
                fprintf(stderr, "Error: missing '=' or ';' near %s", nextLexeme);
                exit(EXIT_FAILURE);
            }

            ast_t *rvalue = NULL;

            while(next_symbol != ';'){

                nextLexeme = lexer_getalphanum(buffer);
                // check the term validity before

                next_symbol = buf_getchar_after_blank(buffer);

                if(next_symbol != '*' && next_symbol != '+' && next_symbol != '/' && next_symbol != '-' && next_symbol != ';'){
                    fprintf(stderr, "Error: missing operator near %s", nextLexeme);
                    exit(EXIT_FAILURE);
                }


                fprintf(stderr, "\noperator %c\n", next_symbol);
            }
        }
    }

    return ast_function_body_node;
}

int analyse_returned_type(buffer_t *buffer){

    char next_symbol = buf_getchar_after_blank(buffer);

    if(next_symbol != ':'){
        fprintf(stderr, "Error missing ':' symbol");
        exit(EXIT_FAILURE);
    }

    char* next_lexeme;

    int type;

    while(next_symbol != '{'){

        next_lexeme = lexer_getalphanum(buffer);

        bool result = is_allowed_type(next_lexeme);

        if(result == false){
            fprintf(stderr, "Error: %s is not a valid type", next_lexeme);
            exit(EXIT_FAILURE);
        }

        type = lexeme_to_type(next_lexeme);

        next_symbol = buf_getchar_rollback(buffer);
    }

    return type;
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
