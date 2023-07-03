#include "../../exports.h"

TEST_GROUP(test_group_analyse_parameter);

static FILE* fp;
static buffer_t buffer;

static ast_list_t *params_list;


TEST_SETUP(test_group_analyse_parameter){

    fp = fopen("program_1.txt", "r");
    if(fp == NULL){
        printf("Could not read the file");
        exit(1);
    }
    buf_init(&buffer, fp);
}

TEST_TEAR_DOWN(test_group_analyse_parameter){
    fclose(fp);
}

TEST(test_group_analyse_parameter, test_function_name_equals_main){

    char *lexeme = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    char *function_name = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("main", function_name, 4);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_NOT_NULL(params_list);

    //TEST_ASSERT_EQUAL(1, params_list->data->var.type);

    //TEST_ASSERT_EQUAL_CHAR_ARRAY("a", params_list->data->var.name, 1);
}
TEST(test_group_analyse_parameter, test_function_param_type_is_entier){

    char *lexeme = lexer_getalphanum(&buffer);

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    char *function_name = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("main", function_name, 4);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_NOT_NULL(params_list);

    TEST_ASSERT_EQUAL(1, params_list->data->var.type);
}
TEST(test_group_analyse_parameter, test_first_function_param_name_equals_nbr){

    char *lexeme = lexer_getalphanum(&buffer);

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    char *function_name = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("main", function_name, 4);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_NOT_NULL(params_list);

    TEST_ASSERT_EQUAL(1, params_list->data->var.type);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("nbr", params_list->data->var.name, 3);
}
TEST(test_group_analyse_parameter, test_second_param_type_is_entier){

    char *lexeme = lexer_getalphanum(&buffer);

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    char *function_name = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("main", function_name, 4);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_EQUAL(1, params_list->next->data->var.type);

    TEST_ASSERT_NOT_NULL(params_list->next->data->var.name);
}
TEST(test_group_analyse_parameter, test_third_param_type_is_entier){

    char *lexeme = lexer_getalphanum(&buffer);

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    char *function_name = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("main", function_name, 4);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_EQUAL(1, params_list->next->next->data->var.type);
}
TEST(test_group_analyse_parameter, test_function_with_two_parameters){

    fp = fopen("program_2.txt", "r");
    if(fp == NULL){
        printf("Could not read the file");
        exit(1);
    }
    buf_init(&buffer, fp);

    char *lexeme = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    char *function_name = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("add", function_name, 3);

    params_list = analyse_parameters(&buffer);

    TEST_ASSERT_EQUAL(32, buffer.it);

    TEST_ASSERT_EQUAL(1, params_list->data->var.type);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("b", params_list->data->var.name, 1);
}
