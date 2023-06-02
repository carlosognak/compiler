#include "../lib/unity_fixture.h"


TEST_GROUP(LexerGetAlphanum);

TEST_GROUP_RUNNER(LexerGetAlphanum){

   RUN_TEST_CASE(LexerGetAlphanum, StringContentMatches);

   RUN_TEST_CASE(LexerGetAlphanum, LengthOfStringMatches);

   RUN_TEST_CASE(LexerGetAlphanum, TheBufferIteratorMoved);

   RUN_TEST_CASE(LexerGetAlphanum, TextStartingWithUnderScore);

   RUN_TEST_CASE(LexerGetAlphanum, TextContainsNumber);

   RUN_TEST_CASE(LexerGetAlphanum, BufferIteratorCurrentPosition);
}


TEST_GROUP(lexergetalphanumhaRollback);

TEST_GROUP_RUNNER(lexergetalphanumhaRollback){

    RUN_TEST_CASE(lexergetalphanumhaRollback, testBufferIteratorNotMoved);
    RUN_TEST_CASE(lexergetalphanumhaRollback, testAlphanumFoundButIteratorNotMoved)
}

TEST_GROUP(GetNumberLexer);

TEST_GROUP_RUNNER(GetNumberLexer){
    RUN_TEST_CASE(GetNumberLexer, FindAllNumber);
}
