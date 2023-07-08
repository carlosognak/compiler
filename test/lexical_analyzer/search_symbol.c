#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../lexical_analizer.h"
#include "../../symbol_t.h"


TEST_GROUP(test_group_search_symbol);

static ast_t *ast_variable;
static symbol_t *head = NULL;

TEST_SETUP(test_group_search_symbol){

}

TEST_TEAR_DOWN(test_group_search_symbol){

}
TEST(test_group_search_symbol, test_symbol_found_within_the_table){

    ast_variable = ast_new_variable("totalComputer",1);

    sym_add(&head, sym_new("totalComputer",1,ast_variable));
    sym_add(&head, sym_new("totalPhone",2,ast_variable));
    sym_add(&head, sym_new("totalDevice",2,ast_variable));
    sym_add(&head, sym_new("totalServer",1,ast_variable));

    TEST_ASSERT_NOT_NULL(sym_search(head, "totalServer"));

}
