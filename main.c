#include <stdio.h>
#include <stdlib.h>

#include "buffer.h"
#include "lexer.h"

int main()
{
    FILE* demo;

    demo = fopen("intech.txt", "r+");

    buffer_t buffer;
    buf_init(&buffer, demo);

    printf("%s\n", lexer_getalphanum(&buffer));
    printf("%s\n", lexer_getalphanum(&buffer));
    printf("%s\n", lexer_getalphanum(&buffer));
    printf("%s\n", lexer_getalphanum(&buffer));

    fclose(demo);
    return 0;
}
