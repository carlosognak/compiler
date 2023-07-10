#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../lexical_analizer.h"
#include "../../symbol_t.h"

TEST_GROUP(test_group_remove_symbol);

static ast_t *ast_variable;
static symbol_t *head = NULL;

TEST_SETUP(test_group_remove_symbol){

}

TEST_TEAR_DOWN(test_group_remove_symbol){

}

static void add_symbol(char* name, int type, ast_t *node){
    sym_add(&head, sym_new(name, type, node));
}
TEST(test_group_remove_symbol, test_symbol_total_computer_successfully_removed){

    ast_variable = ast_new_variable("totalComputer",1);

    add_symbol("totalComputer",1,ast_variable);
    add_symbol("totalPhone",1,ast_variable);
    add_symbol("totalDevice",1,ast_variable);
    add_symbol("totalServer",1,ast_variable);

    symbol_t *totalComputerSymb = sym_search(head, "totalComputer");

    TEST_ASSERT_EQUAL_STRING("totalComputer", totalComputerSymb->name);

    sym_remove(&head, totalComputerSymb);

    TEST_ASSERT_NULL(sym_search(head, "totalComputer"));
}

TEST(test_group_remove_symbol, test_symbol_all_symbol_got_deleted){

    symbol_t *table = NULL;

    ast_variable = ast_new_variable("totalComputer",1);
    sym_add(&table, sym_new("totalComputer",1,ast_variable));
    sym_add(&table, sym_new("totalPhone",1,ast_variable));
    sym_add(&table, sym_new("totalDevice",1,ast_variable));
    sym_add(&table, sym_new("totalServer",1,ast_variable));

    symbol_t *totalComputerSymb = sym_search(table, "totalPhone");

    TEST_ASSERT_EQUAL_STRING("totalPhone", totalComputerSymb->name);

    TEST_ASSERT_NOT_NULL(sym_search(table,"totalPhone"));
    TEST_ASSERT_NOT_NULL(sym_search(table,"totalServer"));
    TEST_ASSERT_NOT_NULL(sym_search(table,"totalComputer"));

    sym_remove(&table, totalComputerSymb);
    sym_remove(&table, sym_search(table, "totalComputer"));
    sym_remove(&table, sym_search(table, "totalServer"));

    TEST_ASSERT_NULL(sym_search(table,"totalPhone"));
    TEST_ASSERT_NULL(sym_search(table,"totalServer"));
    TEST_ASSERT_NULL(sym_search(table,"totalComputer"));
}
