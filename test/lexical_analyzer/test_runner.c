#include "../../exports.h"

TEST_GROUP(new_integer);

TEST_GROUP_RUNNER(new_integer){
    RUN_TEST_CASE(new_integer, test_new_integer_ast_created);
    RUN_TEST_CASE(new_integer, test_new_integer_ast_complementary);
}

TEST_GROUP(new_variable);

TEST_GROUP_RUNNER(new_variable){
    RUN_TEST_CASE(new_variable, test_set_new_variable_success);
    RUN_TEST_CASE(new_variable, test_set_new_variable_complementary);
    RUN_TEST_CASE(new_variable, test_ast_not_null);
    RUN_TEST_CASE(new_variable, test_ast_variable_struct_not_null);
}


TEST_GROUP(new_binary);
TEST_GROUP_RUNNER(new_binary){
    RUN_TEST_CASE(new_binary, test_ast_not_null);
    RUN_TEST_CASE(new_binary, test_binary_right_not_null);
    RUN_TEST_CASE(new_binary, test_binary_left_not_null);
    RUN_TEST_CASE(new_binary, test_binary_op_not_null);
    RUN_TEST_CASE(new_binary, test_binary_right_value);
    RUN_TEST_CASE(new_binary, test_binary_left_value);
}

TEST_GROUP(new_unary);
TEST_GROUP_RUNNER(new_unary){
    RUN_TEST_CASE(new_unary,test_ast_not_null);
    RUN_TEST_CASE(new_unary,test_unary_operand_not_null);
    RUN_TEST_CASE(new_unary,test_unary_op_not_null);
}
