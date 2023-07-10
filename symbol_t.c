#include "symbol_t.h"
#include <stdlib.h>
#include <string.h>

symbol_t *sym_new (char* name, int type, ast_t* attributes){

    symbol_t *new_symbol = (symbol_t *) malloc(sizeof(symbol_t));

    new_symbol->name = name;
    new_symbol->type = type;
    new_symbol->attributes = attributes;
    new_symbol->next = NULL;

    return new_symbol;
}
void sym_delete (symbol_t *sym){

    if (sym->name != NULL) {
        free(sym->name);
    }
    if (sym->attributes != NULL) {
        free(sym->attributes);
    }
    free(sym);
}
void sym_remove (symbol_t**table, symbol_t*sym){

    if (*table == NULL || sym == NULL) {
        return; // Invalid table or symbol pointer
    }

    symbol_t* current = *table;
    symbol_t* previous = NULL;

    // Traverse the table to find the symbol
    while (current != NULL) {

        if (strcmp(current->name, sym->name) == 0) {

            if (previous == NULL) {
                *table = current->next;
            }

            else {
                previous->next = current->next;
            }
            free(current);

            return;
        }
        // Move to the next symbol
        previous = current;
        current = current->next;
    }
}

void sym_add(symbol_t** table, symbol_t* sym){

    symbol_t *symb_tab = sym_new(sym->name, sym->type, sym->attributes);

    symb_tab->next = *table;

    *table = symb_tab;

}
symbol_t* sym_search (symbol_t* table, char*name){

    struct symbol_t* current = table;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current; // Found a symbol with matching name
        }

        current = current->next; // Move to the next symbol in the table
    }
    return NULL; // Symbol not found
}
