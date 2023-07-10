//#include "exports.h"
#include <stdio.h>
#include "syntax_analyzer.h"

int main(int argc, char * argv[])
{
    //return UnityMain(argc, argv, runAllTest);
    FILE* fp;
    buffer_t buffer;
    fp = fopen("./programs/program_5.txt", "r");
    if(fp == NULL){
        printf("Could not read the file program_5.txt for test_group_analyse_function");
        exit(1);
    }
    buf_init(&buffer, fp);

    int parsingResult = parser(&buffer);

    fclose(fp);
}
