#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include "buffer.h"


char *lexer_getalphanum(buffer_t* buffer);

char *lexer_getalphanum_rollback(buffer_t* buffer);

long lexer_getnumber(buffer_t* buffer);

char *lexer_getalphanum_copy(buffer_t* buffer);
#endif // LEXER_H_INCLUDED
