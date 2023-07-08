#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../lexical_analizer.h"

TEST_GROUP(new_function);

static ast_t *ast;
static char *name;
static int returned_type;
static ast_list_t *params;
static ast_list_t *stmts;

TEST_SETUP(new_function){

}

TEST_TEAR_DOWN(new_function){

}
TEST(new_function, test_new_function_params){

}
