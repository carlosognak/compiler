#include <stdio.h>
#include <stdlib.h>
#include "lib/unity_fixture.h"
#include "lexer.h"
#include "buffer.h"

static void runAllTest(void){
    RUN_TEST_GROUP(alphanum);
    RUN_TEST_GROUP(alphanum_rollback);
    RUN_TEST_GROUP(number);
    RUN_TEST_GROUP(lexical_analyser);
    RUN_TEST_GROUP(new_variable);
    RUN_TEST_GROUP(new_binary);
    RUN_TEST_GROUP(new_unary);
}

int main(int argc, char * argv[])
{

    return UnityMain(argc, argv, runAllTest);

}
