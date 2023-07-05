#include "../../exports.h"

TEST_GROUP(test_group_function_body);

static FILE* fp;
static buffer_t buffer;

static ast_list_t *params_list;

static ast_t *tree;

static char *lexeme;

static int returned_type;

TEST_SETUP(test_group_function_body){

    fp = fopen("program_5.txt", "r");
    if(fp == NULL){
        printf("Could not read the file program_5.txt");
        exit(1);
    }
    buf_init(&buffer, fp);
    lexeme = lexer_getalphanum(&buffer);
}

TEST_TEAR_DOWN(test_group_function_body){
    fclose(fp);
}

TEST(test_group_function_body, test_function_body_is_not_empty){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    lexeme = lexer_getalphanum(&buffer);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_EQUAL(32, buffer.it);

    returned_type = analyse_returned_type(&buffer);

    tree = analyse_function_body(&buffer);
}


