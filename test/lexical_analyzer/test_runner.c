#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"

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

TEST_GROUP(ast_list_add);
TEST_GROUP_RUNNER(ast_list_add){
    RUN_TEST_CASE(ast_list_add,test_param_list_not_null);
    RUN_TEST_CASE(ast_list_add, test_parameter_type);
    RUN_TEST_CASE(ast_list_add, test_parameter_name);
}
TEST_GROUP(test_group_new_symbol);
TEST_GROUP_RUNNER(test_group_new_symbol){
    RUN_TEST_CASE(test_group_new_symbol,test_new_symbol_created);
    RUN_TEST_CASE(test_group_new_symbol,test_new_symbol_name_equals_totalComputer);
    RUN_TEST_CASE(test_group_new_symbol,test_new_symbol_name_type_is_one);
}
TEST_GROUP(test_group_add_symbol);
TEST_GROUP_RUNNER(test_group_add_symbol){
    RUN_TEST_CASE(test_group_add_symbol, test_table_head_not_null);
    RUN_TEST_CASE(test_group_add_symbol, test_table_next_symbol_not_null);
    RUN_TEST_CASE(test_group_add_symbol, test_table_next_data_not_null);
    RUN_TEST_CASE(test_group_add_symbol, test_table_next_data_name_equals_totalComputer);
    RUN_TEST_CASE(test_group_add_symbol, test_table_next_has_changed);
}
TEST_GROUP(test_group_search_symbol);
TEST_GROUP_RUNNER(test_group_search_symbol){
    RUN_TEST_CASE(test_group_search_symbol,test_symbol_found_within_the_table);
}
