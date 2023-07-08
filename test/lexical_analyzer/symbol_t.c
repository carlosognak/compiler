/*#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../lexical_analizer.h"
#include "../../symbol_t.h"


TEST_GROUP(test_group_symbol_table);

static ast_t *ast;
static symbol_t *new_symbol;


TEST_SETUP(test_group_symbol_table){

}

TEST_TEAR_DOWN(test_group_symbol_table){

}
TEST(test_group_symbol_table, test_new_symbol_created){
    ast = ast_new_variable("nbr", 3);
    table = sym_new("variable", 1, ast);

    TEST_ASSERT_NOT_NULL(table);

    TEST_ASSERT_EQUAL_STRING("variable", table->name);
}/*
TEST(test_group_symbol_table, test_symbol_name_variable_exist_into_the_table){

    ast = ast_new_variable("nbr", 3);

    table = sym_new("variable", 1, ast);

    TEST_ASSERT_EQUAL_STRING("variable", table->name);
}
TEST(test_group_symbol_table, test_symbol_type_equals_one){

    ast = ast_new_variable("nbr", 3);

    table = sym_new("variable", 1, ast);

    TEST_ASSERT_EQUAL(1, table->type);
}
TEST(test_group_symbol_table, test_symbol_attributes_not_null){

    ast = ast_new_variable("nbr", 3);

    table = sym_new("variable", 1, ast);

    TEST_ASSERT_NOT_NULL(table->attributes);
    TEST_ASSERT_EQUAL(3, table->attributes->var.type);
    TEST_ASSERT_EQUAL_STRING("nbr", table->attributes->var.name);
}
TEST(test_group_symbol_table, test_next_symbol_not_null){

    ast = ast_new_variable("name", 3);

    table = sym_new("name", 3, ast);

    ast_t* variable = ast_new_variable("add", 1);

    symbol_t *next_symbol = sym_new("add",1, variable);

    TEST_ASSERT_NOT_NULL(next_symbol);

    sym_add(&table, next_symbol);

    TEST_ASSERT_NOT_NULL(table->next);
}
TEST(test_group_symbol_table, test_next_symbol_data_not_null){

    ast = ast_new_variable("name", 3);

    table = sym_new("name", 3, ast);

    TEST_ASSERT_EQUAL_STRING("name", table->name);

    ast_t* variable = ast_new_variable("add", 1);

    symbol_t *next_symbol = sym_new("add",1, variable);

    TEST_ASSERT_NOT_NULL(next_symbol);

    sym_add(&table, next_symbol);

    TEST_ASSERT_NOT_NULL(table->data);
    TEST_ASSERT_EQUAL_STRING("add", table->data->name);
}
*/
