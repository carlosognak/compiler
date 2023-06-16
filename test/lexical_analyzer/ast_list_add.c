#include "../../exports.h"

TEST_GROUP(ast_list_add);

ast_t *first_variable;
ast_t *second_variable;

ast_list_t *param_list;

TEST_SETUP(ast_list_add){

    first_variable = ast_new_variable("a", 1);
    second_variable = ast_new_variable("b",2);
    param_list = ast_list_add(param_list, first_variable);
}

TEST_TEAR_DOWN(ast_list_add){
}

TEST(ast_list_add, test_param_list_not_null){

    TEST_ASSERT_NOT_NULL(param_list);
}
TEST(ast_list_add, test_parameter_type){

    TEST_ASSERT_NOT_NULL(param_list->data->var.type);
    TEST_ASSERT_EQUAL(1, param_list->data->var.type);
}
TEST(ast_list_add, test_parameter_name){

    TEST_ASSERT_NOT_NULL(param_list->data->var.name);
    TEST_ASSERT_EQUAL("a", param_list->data->var.name);
}
