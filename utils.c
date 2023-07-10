
#include <stdlib.h>
#include <string.h>
#ifndef WIN32
#include <unistd.h>
#include <execinfo.h>
#endif

#include "buffer.h"
#include "utils.h"
#include "ast_struct.h"
#include "lexer.h"
#include <stdlib.h>
#include <ctype.h>


char *copy_name (char *name)
{
  size_t len = strlen(name) + 1;
  char *out = malloc(sizeof(char) * len);
  strncpy(out, name, len);
  return out;
}

void print_backtrace ()
{
#ifndef WIN32
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  backtrace_symbols_fd(array, size, STDERR_FILENO);
#endif /* WIN32 */
}

int check_lexeme_is_digit_or_error(char* lexeme){
    if(is_lexeme_digit(lexeme)){
        fprintf(stderr, "Error: %s constant number cannot be used as a variable name.", lexeme);
        exit(EXIT_FAILURE);
    }
    return 0;
}
int check_lexeme_is_keyword_or_error(char *lexeme){
    if(is_lexeme_keyword(lexeme) == false){
        fprintf(stderr, "Error: %s unknown keyword.", lexeme);
        exit(EXIT_FAILURE);
    }
    return 0;
}
int check_lexeme_is_valid_type_or_error(char* lexeme){
    if(is_allowed_type(lexeme) == false){
        fprintf(stderr, "Error: %s is not a valid type.",lexeme);
        exit(EXIT_FAILURE);
    }
    return 0;
}
bool is_lexeme_keyword(char *lexeme){
    if(is_lexeme_type_entier(lexeme))
        return true;

    else if(is_lexeme_keyword_si(lexeme))
        return true;

    else if(is_lexeme_keyword_sinon(lexeme))
        return true;

    return false;
}
bool is_lexeme_type_entier(char* lexeme){
    if(strcmp(lexeme, "entier") == 0)
        return true;
    return false;
}
bool is_lexeme_type_char(char* lexeme){
    if(strcmp(lexeme, "char") == 0)
        return true;
    return false;
}
bool is_allowed_type(char* lexeme){

    if(strcmp(lexeme,"entier") == 0){
        return true;
    }

    else if(strcmp(lexeme,"char") == 0){
         return true;
    }
    else if(strcmp(lexeme, "rien") == 0){
        return true;
    }
    return false;
}
int is_lexeme_empty(char* lexeme){
    if(strlen(lexeme) < 0)
        return 1;
    return 0;
}

bool is_lexeme_digit(char *lexeme){
    for(int i = 0; i < strlen(lexeme); i++){
        if(isdigit(lexeme[i]) == false)
            return false;
    }

    return true;
}
int lexeme_to_type(char* lexeme){
    if(is_lexeme_type_entier(lexeme))
        return 1;

    else if(strcmp(lexeme, "rien") == 0)
        return 0;

    else if(strcmp(lexeme, "char") == 0)
        return 2;

    return -1;
}
bool is_lexeme_keyword_si(char *lexeme){
    if(strcmp(lexeme, "si") == 0)
        return true;

    return false;
}
bool is_lexeme_keyword_sinon(char* lexeme){
    if(strcmp(lexeme, "sinon") == 0)
        return true;

    return false;
}
bool is_lexeme_keyword_tanque(char* lexeme){
    if(strcmp(lexeme, "tanque") == 0)
        return true;
    return false;
}
ast_list_t *add_statement_to_list(buffer_t *buffer, ast_list_t **statements_list){

    char *next_lexeme = lexer_getalphanum(buffer);

    int type = lexeme_to_type(next_lexeme);
   // get the variable name

    next_lexeme = lexer_getalphanum(buffer);

    ast_t * variable_node = NULL;
    ast_t * declaration_node = NULL;

    char next_symbol = buf_getchar_rollback(buffer);

    if(next_symbol != ';' && next_symbol != '='){
        fprintf(stderr, "Error: missing '=' near %s", next_lexeme);
        exit(EXIT_FAILURE);
    }
    else if(next_symbol == ';'){
        variable_node = ast_new_variable(next_lexeme, type);
        if(variable_node == NULL){
            fprintf(stderr, "Error: variable node could not be created for: %s", next_lexeme);
            exit(EXIT_FAILURE);
        }
        declaration_node = ast_new_declaration(variable_node,NULL);
    }
    next_symbol = buf_getchar_after_blank(buffer);

    statements_list = ast_list_add(&statements_list, declaration_node);

    return statements_list;

}
