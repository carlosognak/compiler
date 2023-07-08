#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../lexical_analizer.h"

TEST_GROUP(new_unary);

static ast_t *ast;

static ast_t *operand;

static ast_unary_e op;

TEST_SETUP(new_unary){

    operand = ast_new_variable("incrementor", 1);
    op = OP_INCREMENT;
    ast = ast_new_unary(op, operand);
}

TEST_TEAR_DOWN(new_unary){

}

TEST(new_unary, test_ast_not_null){
    TEST_ASSERT_NOT_NULL(ast);
}
TEST(new_unary, test_unary_operand_not_null){
    TEST_ASSERT_NOT_NULL(ast->unary.operand);
}
TEST(new_unary, test_unary_op_not_null){
    TEST_ASSERT_EQUAL(OP_INCREMENT, ast->unary.op);
}
