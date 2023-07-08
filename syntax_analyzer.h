#ifndef SYNTAX_ANALYZER_H_INCLUDED
#define SYNTAX_ANALYZER_H_INCLUDED


#include "buffer.h"
#include "ast_struct.h"

ast_t *analyse_function(buffer_t *buffer);

ast_list_t *analyse_parameters(buffer_t *buffer);

ast_t *analyse_function_body(buffer_t *buffer);

int analyse_returned_type(buffer_t *buffer);

int parser(buffer_t *buffer);

#endif // SYNTAX_ANALYZER_H_INCLUDED
