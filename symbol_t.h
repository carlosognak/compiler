#ifndef SYMBOL_T_H_INCLUDED
#define SYMBOL_T_H_INCLUDED

#include "buffer.h"
#include "ast_struct.h"

typedef struct symbol_t{
    char *name;
    int type;
    struct symbol_t *next;
    struct symbol_t *data;
    ast_t *attributes;
}symbol_t;

symbol_t* sym_new(char*name, int type, ast_t *attributes);
void sym_delete(symbol_t* sym);
void sym_remove(symbol_t** table, symbol_t*sym);
void sym_add(symbol_t**table, symbol_t*sym);
symbol_t* sym_search (symbol_t*table, char*name);

#endif // SYMBOL_T_H_INCLUDED
