/*
 * Version: 1.0
 * --------------------------
 * Authors: BAHAMBOULA IDOURAH C.Y

 * Lexers used in the lexical analysis of Intech compiler programming langage
 *
 * Date: 15/05/2023
 */

#include "lexer.h"
#include "assert.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"

/*
 * Function lexer_getalphanum
 * --------------------------
 * Extracts a alphanumeric string from the buffer
 * while moving the buffer iterator
 *
 * buffer: the abstract buffer data structure
 *
 * return: the alphanumeric string extracted from buffer
 */


long convertStringToLong(char * str){

    assert(strlen(str) != 0);

    long number;

    if(!isdigit(str[0])){
        return;
    }

    if(!sscanf(str, "%ld", &number)){
        return;
    }

    return number;
}

char *lexer_getalphanum(buffer_t* buffer){

    assert((!buf_eof(buffer) && buffer != NULL));

    bool buffer_was_locked_before;

    if(buffer->islocked){
        buffer_was_locked_before = true;
    }

    char *str = malloc(sizeof(char) * 1);

    char buf_char = buf_getchar_after_blank(buffer);

    int length = 0;


    while(true){

        length++;

        str = realloc(str, length + 1);

        str[length - 1] = buf_char;

        if(buffer->islocked){
            buf_unlock(buffer);
        }

        buf_lock(buffer);
        buf_char = buf_getchar(buffer);

        if(!isalnum(buf_char) && buf_char != '_'){

            buf_rollback_and_unlock(buffer, 1);

            if(buffer_was_locked_before){
                buf_lock(buffer);
            }
            break;
        }
        buf_unlock(buffer);
    }

    str[length] = '\0';
    return str;
}



/*
 * Function lexer_getalphanum_rollback
 * --------------------------
 * Extracts a alphanumeric string from the buffer
 * but the buffer iterator stays at it initial position
 *
 * buffer
 : the abstract buffer data structure
 *
 * return: the alphanumeric string extracted from buffer
 */

char *lexer_getalphanum_rollback(buffer_t* buffer){

    buf_lock(buffer);

    char *str = lexer_getalphanum(buffer);

    buf_rollback_and_unlock(buffer, strlen(str));

    return str;
}

/*
 * Function lexer_getnumber
 * --------------------------
 * Extracts number from the buffer
 *
 * buffer: the abstract buffer data structure
 *
 * return: the number extracted from buffer
 */

long lexer_getnumber(buffer_t* buffer){

    assert(!buf_eof(buffer));

    char * str = lexer_getalphanum(buffer);

    while(!isdigit(str[0])){

        str = lexer_getalphanum(buffer);
    }

    return atol(str);
}
