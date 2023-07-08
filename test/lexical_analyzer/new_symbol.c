#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../lexical_analizer.h"
#include "../../symbol_t.h"


TEST_GROUP(test_group_new_symbol);

static ast_t *ast_variable;
static symbol_t *new_symbol;



TEST_SETUP(test_group_new_symbol){

}

TEST_TEAR_DOWN(test_group_new_symbol){

}
TEST(test_group_new_symbol, test_new_symbol_created){
    ast_variable = ast_new_variable("totalComputer",1);
    new_symbol = sym_new("totalComputer",1,ast_variable);

    TEST_ASSERT_NOT_NULL(new_symbol);
}
TEST(test_group_new_symbol, test_new_symbol_name_equals_totalComputer){

    ast_variable = ast_new_variable("totalComputer",1);
    new_symbol = sym_new("totalComputer",1,ast_variable);

    TEST_ASSERT_EQUAL_STRING("totalComputer", new_symbol->name);
}
TEST(test_group_new_symbol, test_new_symbol_name_type_is_one){

    ast_variable = ast_new_variable("totalComputer",1);
    new_symbol = sym_new("totalComputer",1,ast_variable);

    TEST_ASSERT_EQUAL(1, new_symbol->type);
}
