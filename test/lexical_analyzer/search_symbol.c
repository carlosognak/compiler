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
static void add_symbol(char* name, int type, ast_t *node){
    sym_add(&head, sym_new(name, type, node));
}
TEST(test_group_search_symbol, test_symbol_found_within_the_table){

    ast_variable = ast_new_variable("totalComputer",1);

    add_symbol("totalComputer",1,ast_variable);
    add_symbol("totalPhone",1,ast_variable);
    add_symbol("totalDevice",1,ast_variable);
    add_symbol("totalServer",1,ast_variable);

    symbol_t *sym = sym_search(head, "totalComputer");

    TEST_ASSERT_EQUAL_STRING("totalComputer", sym->name);
}
TEST(test_group_search_symbol, test_totalDevice_symbol_found_in_table){

    ast_variable = ast_new_variable("totalComputer",1);

    add_symbol("totalComputer",1,ast_variable);
    add_symbol("totalPhone",1,ast_variable);
    add_symbol("totalDevice",1,ast_variable);
    add_symbol("totalServer",1,ast_variable);

    symbol_t *sym = sym_search(head, "totalDevice");
    TEST_ASSERT_EQUAL_STRING("totalDevice", sym->name);
}
TEST(test_group_search_symbol, test_symbol_does_not_exist_true){

    ast_variable = ast_new_variable("totalComputer",1);

    add_symbol("totalComputer",1,ast_variable);
    add_symbol("totalPhone",1,ast_variable);
    add_symbol("totalDevice",1,ast_variable);
    add_symbol("totalServer",1,ast_variable);

    symbol_t *sym = sym_search(head, "totalIphone");
    TEST_ASSERT_NULL(sym);
}
