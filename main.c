#include <stdio.h>
#include <stdlib.h>
#include "lib/unity_fixture.h"
#include "lexer.h"
#include "buffer.h"

static void runAllTest(void){
    RUN_TEST_GROUP(LexerGetAlphanum);
    RUN_TEST_GROUP(lexergetalphanumhaRollback);
    RUN_TEST_GROUP(Lexer_GetNumber);
}

int main(int argc, char * argv[])
{

    return UnityMain(argc, argv, runAllTest);

}
