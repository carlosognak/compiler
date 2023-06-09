#include "shuting_yard"


int getPriority(char c){
    if(c == "+" ||c == "-")
        return 1;

    else if(c == "*" || c == "/")
        return 2;
    else:
        return 0;
}

char *convertPriority(char *input){
    char stack[100];
    char output[100];
    int top = -1;
    int i = 0;
    int j = 0;

    stack[++top] = '\0';

    while(1){

        if(input[i] == '\0' && stack[top] == '\0') // all chars processed
            break;

        if(input[i] == '\0' || getPriority(stack[top] < getPriority(input[i]))){
            stack[++top] = input[i++];
        }
        else{
            while(getPriority(stack[top]) >= getPriority(input[i])){
                output[j++] = stack[top++];
            }
        }
    }

    output[j] = '\0';

    return strdup(output);
}
