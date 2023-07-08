#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../lexical_analizer.h"


TEST_GROUP(new_variable);

static ast_t *ast;

TEST_SETUP(new_variable){

}

TEST_TEAR_DOWN(new_variable){

}
TEST(new_variable, test_ast_not_null){
    ast = ast_new_variable("nbr", 3);
    TEST_ASSERT_NOT_NULL(ast);
}
TEST(new_variable, test_ast_variable_struct_not_null){
    ast = ast_new_variable("nbr", 3);
    TEST_ASSERT_NOT_NULL(ast->var.type);
    TEST_ASSERT_NOT_NULL(ast->var.name);
}
TEST(new_variable, test_set_new_variable_success){
    ast = ast_new_variable("car_nbr", 2);
    TEST_ASSERT_EQUAL(2, ast->var.type);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("car_nbr", ast->var.name,7);
}
TEST(new_variable, test_set_new_variable_complementary){
    ast = ast_new_variable("car_nbr", 2);
    TEST_ASSERT_NOT_EQUAL(1, ast->var.type);
    TEST_ASSERT_NOT_EQUAL("car", ast->var.name);
    TEST_ASSERT_EQUAL("car_nbr", ast->var.name);
}



