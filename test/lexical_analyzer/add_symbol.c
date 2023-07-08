#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../lexical_analizer.h"
#include "../../symbol_t.h"


TEST_GROUP(test_group_add_symbol);

static ast_t *ast_variable;
static symbol_t *head = NULL;

TEST_SETUP(test_group_add_symbol){

}

TEST_TEAR_DOWN(test_group_add_symbol){

}
TEST(test_group_add_symbol, test_table_head_not_null){

    ast_variable = ast_new_variable("totalComputer",1);
    symbol_t *new_symbol = sym_new("totalComputer",1,ast_variable);

    sym_add(&head, new_symbol);

    TEST_ASSERT_NOT_NULL(head);
}
TEST(test_group_add_symbol, test_table_next_symbol_not_null){

    ast_variable = ast_new_variable("totalComputer",1);
    symbol_t *new_symbol = sym_new("totalComputer",1,ast_variable);

    sym_add(&head, new_symbol);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_NOT_NULL(head->next);
}
TEST(test_group_add_symbol, test_table_next_data_not_null){

    ast_variable = ast_new_variable("totalComputer",1);
    symbol_t *new_symbol = sym_new("totalComputer",1,ast_variable);

    sym_add(&head, new_symbol);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_NOT_NULL(head->next->data);
}
TEST(test_group_add_symbol, test_table_next_data_name_equals_totalComputer){

    ast_variable = ast_new_variable("totalComputer",1);
    symbol_t *new_symbol = sym_new("totalComputer",1,ast_variable);

    sym_add(&head, new_symbol);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_NOT_NULL(head->next->data);
    TEST_ASSERT_EQUAL("totalComputer", head->next->data->name);
}
TEST(test_group_add_symbol, test_table_next_has_changed){

    ast_variable = ast_new_variable("totalComputer",1);

    sym_add(&head, sym_new("totalComputer", 1, ast_variable));
    TEST_ASSERT_NOT_NULL(head->next->data);
    TEST_ASSERT_EQUAL("totalComputer", head->data->name);


    sym_add(&head, sym_new("totalPhone", 2, ast_variable));
    TEST_ASSERT_EQUAL_STRING("totalPhone", head->data->name);

    sym_add(&head, sym_new("totalDevice", 2, ast_variable));
    TEST_ASSERT_EQUAL_STRING("totalDevice", head->data->name);
}
