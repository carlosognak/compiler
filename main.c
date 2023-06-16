#include "exports.h"

static void runAllTest(void){

    // lexical analysis functions group runnners
    RUN_TEST_GROUP(alphanum);
    RUN_TEST_GROUP(alphanum_rollback);
    RUN_TEST_GROUP(number);

    // lexical analyzer group test runners
    RUN_TEST_GROUP(new_integer);
    RUN_TEST_GROUP(new_variable);
    RUN_TEST_GROUP(new_binary);
    RUN_TEST_GROUP(new_unary);
    RUN_TEST_GROUP(ast_list_add);

    // syntax analyzer test runner group
    RUN_TEST_GROUP(test_analyse_function);
}

int main(int argc, char * argv[])
{
    return UnityMain(argc, argv, runAllTest);

}
