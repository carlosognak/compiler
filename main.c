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
}

int main(int argc, char * argv[])
{
    return UnityMain(argc, argv, runAllTest);

}
