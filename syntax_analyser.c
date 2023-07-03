#include "syntax_analyser.h"
#include <errno.h>

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


ast_list_t *analyse_parameters(buffer_t *buffer){

    ast_list_t *parameter_list_node = NULL;

    char next_char = buf_getchar_after_blank(buffer);

    if(next_char != '('){
        fprintf(stderr, "missing '(' after function name", strerror(errno));
        exit(EXIT_FAILURE);
    }
    char *type_lexeme;
    char *function_name_lexeme;
    char *next_lexeme;

    do{

        next_lexeme = lexer_getalphanum(buffer); // get parameter type

        if(is_allowed_type(next_lexeme) == 0){
            fprintf(stderr, "Error: %s is unknown type.",);
            exit(EXIT_FAILURE);
        }

        next_lexeme = lexer_getalphanum(buffer);

        if(is_lexeme_empty(next_lexeme) == 0){
            fprintf(stderr, "missing parameter.");
            exit(EXIT_FAILURE);
        }
        fprintf(stderr, "parameter.",);

        function_name_lexeme = lexer_getalphanum(buffer); // get parameter name
        // check the existence of parameter name in the symbol table
        // does not exist add it in the symbol table
        // create the ast list of type parameter
        ast_t *variable_node = ast_new_variable(type_lexeme, function_name_lexeme);

        next_lexeme = lexer_getalphanum(buffer);

        parameter_list_node = ast_list_add(parameter_list_node, variable_node);

    }while(next_lexeme != ")" );

    return parameter_list_node;

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
