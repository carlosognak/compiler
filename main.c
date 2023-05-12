#include <stdio.h>
#include <stdlib.h>
#include "lib/unity_fixture.h"

static void runAllTest(void){
    RUN_TEST_GROUP(lexergetalphanum);
    RUN_TEST_GROUP(lexergetalphanumhaRollback);
}

int main(int argc, char * argv[])
{
    return UnityMain(argc, argv, runAllTest);

}
