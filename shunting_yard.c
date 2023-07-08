#include "shunting_yard.h"
#include "stack.h"

int get_precedence(char ch){
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return -1;
}
/*
bool has_left_associativity(char ch){
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*') {
        return true;
    }
    return false;
}

char *infix_to_reverse_polish_notation(buffer_t *buffer){

    char next_symbole = buf_getchar_after_blank(buffer);

    while(true){

        if(next_symbole == ';')
            break;

        else if(next_symbole == ')')
            push(next_symbole);

        else if(next_symbole == ')'){
            while(!isempty() && peek() != '(')
                // output += pop()

            //pop();

        }
        // If an operator is encountered then taken the
        // further action based on the precedence of the
            // operator


    }
}
*/
