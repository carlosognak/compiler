#include "lexer.h"
#include "assert.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

char *lexer_getalphanum(buffer_t* buffer){

    char *str = malloc(sizeof(char) * 1);

    char buf_char = buf_getchar(buffer);

    int length = 0;

    while(isalnum(buf_char)){

        length++;

        str = realloc(str, length + 1);

        str[length - 1] = buf_char;

        buf_char = buf_getchar(buffer);
    }

    str[length] = '\0';

    return str;
}
