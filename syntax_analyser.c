#include "syntax_analyser.h"
#include <errno.h>

ast_t *analyse_function(buffer_t *buffer){

    ast_t *function_tree =  NULL;

    // open file and give it to the buffer
    // get the lexeme using get_alphanum
    // if lexeme  is not function terminate the program
    char *function_name = lexer_getalphanum(buffer); // main

    ast_list_t *stmts_list = NULL;

    // analyze function name

    ast_list_t *list_of_params = analyse_parameters(buffer);
    function_tree = ast_new_function(function_name, 1, list_of_params, stmts_list);

    return function_tree;
}

ast_list_t *analyse_parameters(buffer_t *buffer){

    ast_list_t *parameter_list_node = NULL;

    char next_char = buf_getchar_after_blank(buffer);

    if(next_char != '(')
        fprintf(stderr, "missing open bracket for function", strerror(errno));
        exit(EXIT_FAILURE);

    char *type_lexeme;
    char *function_name_lexeme;
    char *next_lexeme;

    do{

        type_lexeme = lexer_getalphanum(buffer); // get parameter type

        if(!strcmp(type_lexeme, "entier"))
            return; // should return a error

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

ast_t *analyse_function_body(buffer *buffer){



}
ast_t *analyse_returned_type(buffer_t *buffer){

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
