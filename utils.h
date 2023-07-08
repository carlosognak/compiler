#ifndef UTILS_H
#define UTILS_H

#define DEBUG true
// #define DEBUG false
#include <stdio.h>
#define COLOR_BLUE ""
#define COLOR_GREEN ""
#define COLOR_RED ""
#define COLOR_BG_RED ""
#define COLOR_BG_BLUE ""
#define COLOR_BG_GREEN ""
#define COLOR_DEFAULT ""

#define STREQUAL 0
#include <stdbool.h>
#include "ast_struct.h"
#include "buffer.h"

int check_lexeme_is_digit_or_error(char* lexeme);
int check_lexeme_is_keyword_or_error(char *lexeme);
int check_lexeme_is_valid_type_or_error(char*);

ast_list_t *add_statement_to_list(buffer_t *buffer, ast_list_t **statements_list);

char *copy_name (char *name);
void print_backtrace ();
bool is_lexeme_keyword(char *lexeme);
bool is_lexeme_type_entier(char*);
bool is_lexeme_keyword_tanque(char*);
bool is_lexeme_keyword_si(char*);
bool is_lexeme_keyword_sinon(char*);
bool is_allowed_type(char*);

int is_valid_parameter(char*);
int is_lexeme_empty(char *);
int lexeme_to_type(char*);
bool is_lexeme_digit(char*);



#endif /* ifndef UTILS_H */
