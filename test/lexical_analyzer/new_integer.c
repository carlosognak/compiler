#include "../../lib/unity_fixture.h""
#include "../../lib/unity.h"
#include "../../lexical_analizer.h"
#include "../../ast_struct.h"


TEST_GROUP(lexical_analyser);

ast_t *ast;

TEST_SETUP(lexical_analyser){

}

TEST_TEAR_DOWN(lexical_analyser){

}
TEST(lexical_analyser, test_new_integer_ast_created){
    ast = ast_new_integer(13);
    TEST_ASSERT_EQUAL(13, ast->integer);
}
TEST(lexical_analyser, test_new_integer_ast_complementary){
    ast = ast_new_integer(14);
    TEST_ASSERT_NOT_EQUAL(15, ast->integer);
}



