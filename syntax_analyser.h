#ifndef SYNTAX_ANALYSER_H_INCLUDED
#define SYNTAX_ANALYSER_H_INCLUDED
#include "exports.h"

ast_t *analyse_function(buffer_t *buffer);
ast_list_t  *analyse_parameters(buffer_t *buffer);
ast_t *analyse_function_body(buffer *buffer);
ast_t *analyse_returned_type(buffer_t *buffer);

void parser(buffer_t *buffer);

#endif // SYNTAX_ANALYSER_H_INCLUDED
