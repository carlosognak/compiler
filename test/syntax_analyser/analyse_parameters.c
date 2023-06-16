#include "../../exports.h"

TEST_GROUP(test_analyse_function);


ast_t *function_tree;
static FILE* fp;
static buffer_t buffer;

static ast_list_t *params_list;


TEST_SETUP(test_analyse_function){

    fp = fopen("program_1.txt", "r");
    if(fp == NULL){
        printf("Could not read the file");
        exit(1);
    }
    buf_init(&buffer, fp);
}

TEST_TEAR_DOWN(test_analyse_function){
    fclose(fp);
}

TEST(test_analyse_function, test_function_name_equals_main){

    char *lexeme = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    char *function_name = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("main", function_name, 4);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_EQUAL(24, buffer.it);

    TEST_ASSERT_NOT_NULL(params_list);

    TEST_ASSERT_EQUAL(1, params_list->data->var.type);

    TEST_ASSERT_EQUAL_CHAR_ARRAY("a", params_list->data->var.name, 1);
}

TEST(test_analyse_function, test_function_param_type_not_null){

}

TEST(test_analyse_function, test_function_param_name_not_null){

}
