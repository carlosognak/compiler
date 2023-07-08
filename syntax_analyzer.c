#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>  // <cstdlib> en C++

#include "utils.h"
#include "syntax_analyzer.h"
#include "lexer.h"
#include "lexical_analizer.h"



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

    ast_t *node = NULL;

    ast_list_t *statements_list = NULL;

    if(next_symbol != '{'){
        fprintf(stderr, "Error missing '{' symbol");
        exit(EXIT_FAILURE);
    }

    ast_t *ast_function_body_node = NULL;

    char* nextLexeme;

    while(true){

        next_symbol = buf_getchar_rollback(buffer);

        if(next_symbol == '}')
            break;

        nextLexeme = lexer_getalphanum_rollback(buffer);

        if(is_lexeme_keyword(nextLexeme) == false){
            fprintf(stderr, "Error: %s unknown keyword.", nextLexeme);
            exit(EXIT_FAILURE);
        }

        else if(is_lexeme_type_entier(nextLexeme)){

            statements_list = add_statement_to_list(buffer, statements_list);
        }
        else if(is_lexeme_keyword_si(nextLexeme)){

            next_symbol = buf_getchar_after_blank(buffer);

            if(next_symbol != '('){
               fprintf(stderr, "Error: missing '(' near %s", nextLexeme);
               exit(EXIT_FAILURE);
            }
            fprintf(stderr, "%s lexeme is this", nextLexeme);
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

    char *next_lexeme;

    ast_t *function_node = NULL;

    ast_list_t *functions_list = NULL;

    int function_counter = 0;

    while(true){


        if(buf_eof(buffer)){
            break;
        }

        next_lexeme= lexer_getalphanum(buffer);

        if(strcmp(next_lexeme, "fonction") == 1){
            fprintf(stderr, "Error: invalid keyword encountered %s", next_lexeme);
            exit(EXIT_FAILURE);
        }
        else if(strcmp(next_lexeme, "fonction") == 0){

            function_node = analyse_function(buffer);

            functions_list = ast_list_add(&functions_list, function_node);

            function_counter += 1;
        }

    }

    if(buf_eof(buffer) && function_counter == 0){
        fprintf(stderr, "Error: Invalid file no function found");
        exit(EXIT_FAILURE);
    }

    return 0;
}
