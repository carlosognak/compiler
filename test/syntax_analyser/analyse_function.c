#include "../../exports.h"


TEST_GROUP(test_group_analyse_function);

static FILE* fp;
static buffer_t buffer;

static ast_t *ast;
static char *lexeme;


TEST_SETUP(test_group_analyse_function){

    fp = fopen("program_1.txt", "r");
    if(fp == NULL){
        printf("Could not read the file");
        exit(1);
    }
    buf_init(&buffer, fp);
    lexeme = lexer_getalphanum(&buffer);
}

TEST_TEAR_DOWN(test_group_analyse_function){
    fclose(fp);
}

TEST(test_group_analyse_function, test_ast_returned_not_null){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    ast = analyse_function(&buffer);

    TEST_ASSERT_NOT_NULL(ast);
}

TEST(test_group_analyse_function, test_function_name_not_null){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    ast = analyse_function(&buffer);

    TEST_ASSERT_NOT_NULL(ast->function.name);
}

TEST(test_group_analyse_function, test_function_name_equals_main){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    ast = analyse_function(&buffer);

    TEST_ASSERT_EQUAL_CHAR_ARRAY("main", ast->function.name, 4);
}

TEST(test_group_analyse_function, test_function_param_type_not_null){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    ast = analyse_function(&buffer);

    TEST_ASSERT_EQUAL(1, ast->function.params->data->var.type);
}
TEST(test_group_analyse_function, test_function_param_name_not_null){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    ast = analyse_function(&buffer);

    //TEST_ASSERT_EQUAL_CHAR_ARRAY("a", ast->function.params->data->var.name, 1);
}
TEST(test_group_analyse_function, test_function_with_multi_params){
    fp = fopen("program_2.txt", "r");
    if(fp == NULL){
        printf("Could not read the file");
        exit(1);
    }
    buf_init(&buffer, fp);
    lexeme = lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("function", lexeme, 8);

    ast = analyse_function(&buffer);

    TEST_ASSERT_EQUAL_CHAR_ARRAY("b", ast->function.params->data->var.name, 1);
}
