#include "../../exports.h"

TEST_GROUP(new_binary);

ast_t *ast;
ast_t *right;
ast_t *left;

ast_binary_e op;

TEST_SETUP(new_binary){

    right = ast_new_integer(12);
    left = ast_new_integer(12);
    op = OP_GREATER_THAN;
}

TEST_TEAR_DOWN(new_binary){

}

TEST(new_binary, test_ast_not_null){

    ast = ast_new_binary(op, right, left);
    TEST_ASSERT_NOT_NULL(ast);
}

TEST(new_binary, test_binary_right_not_null){

    ast = ast_new_binary(op, right, left);
    TEST_ASSERT_NOT_NULL(ast->binary.right);
}
TEST(new_binary, test_binary_left_not_null){
    ast = ast_new_binary(op, right, left);
    TEST_ASSERT_NOT_NULL(ast->binary.left);
}
TEST(new_binary, test_binary_op_not_null){
    ast = ast_new_binary(op, right, left);
    TEST_ASSERT_EQUAL(OP_GREATER_THAN, ast->binary.op);
}
TEST(new_binary, test_binary_right_value){
    ast = ast_new_binary(op, right, left);
    TEST_ASSERT_EQUAL(12, ast->binary.right->integer);
}
TEST(new_binary, test_binary_left_value){
    ast = ast_new_binary(op, right, left);
    TEST_ASSERT_EQUAL(12, ast->binary.left->integer);
}
