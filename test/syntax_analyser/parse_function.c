#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../syntax_analyzer.h"
#include "../../buffer.h"
#include "../../ast_struct.h"
#include <stdio.h>

TEST_GROUP(test_group_parse_function);

static FILE* fp;
static buffer_t buffer;

TEST_SETUP(test_group_parse_function){

    fp = fopen("./programs/program_5.txt", "r");
    if(fp == NULL){
        printf("Could not read the file program_1.txt for test_group_analyse_function");
        exit(1);
    }
    buf_init(&buffer, fp);
}

TEST_TEAR_DOWN(test_group_parse_function){
    fclose(fp);
}

TEST(test_group_parse_function, test_file_successfully_parsed){

   // int result = parser(&buffer);

}




