#ifndef SHUNTING_YARD_H_INCLUDED
#define SHUNTING_YARD_H_INCLUDED

#include <stdbool.h>
#include "buffer.h"
#include "lexer.h"

int getPriority(char c);

int get_precedence(char ch);

bool has_left_associativity(char ch);

char *infix_to_reverse_polish_notation(buffer_t *buffer);

#endif // SHUNTING_YARD_H_INCLUDED
