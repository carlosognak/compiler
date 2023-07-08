#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../lexical_analizer.h"

TEST_GROUP(new_integer);

static ast_t *ast;

TEST_SETUP(new_integer){

}

TEST_TEAR_DOWN(new_integer){

}
TEST(new_integer, test_new_integer_ast_created){
    ast = ast_new_integer(13);
    TEST_ASSERT_EQUAL(13, ast->integer);
}
TEST(new_integer, test_new_integer_ast_complementary){
    ast = ast_new_integer(14);
    TEST_ASSERT_NOT_EQUAL(15, ast->integer);
}



