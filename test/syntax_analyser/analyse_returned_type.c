#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../syntax_analyzer.h"
#include "../../lexer.h"
#include "../../buffer.h"
#include "../../ast_struct.h"
#include <stdio.h>


TEST_GROUP(analyse_returned_type);

static FILE* fp;
static buffer_t buffer;
static ast_list_t *params_list;
static char *lexeme;
static int returned_type;

TEST_SETUP(analyse_returned_type){

    fp = fopen("./programs/program_3.txt", "r");
    if(fp == NULL){
        printf("Could not read the file program_3.txt for test_group_analyse_returned_type");
        exit(1);
    }
    buf_init(&buffer, fp);
    lexeme = lexer_getalphanum(&buffer);
}

TEST_TEAR_DOWN(analyse_returned_type){
    fclose(fp);
}

TEST(analyse_returned_type, test_returned_type_equals_rien){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    lexeme = lexer_getalphanum(&buffer);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_EQUAL(32, buffer.it);

    returned_type = analyse_returned_type(&buffer);

    TEST_ASSERT_EQUAL(0, returned_type);

}

TEST(analyse_returned_type,test_returned_type_equals_entier){

    fp = fopen("./programs/program_4.txt", "r");
    if(fp == NULL){
        printf("Could not read the file program_4.txt for test_group_analyse_returned_type");
        exit(1);
    }
    buf_init(&buffer, fp);

    lexer_getalphanum(&buffer);

    lexer_getalphanum(&buffer);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_EQUAL(32, buffer.it);

    returned_type = analyse_returned_type(&buffer);

    TEST_ASSERT_EQUAL_INT(1, returned_type);
}

