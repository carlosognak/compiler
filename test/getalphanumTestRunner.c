#include "../lib/unity_fixture.h"


TEST_GROUP(lexergetalphanum);

TEST_GROUP_RUNNER(lexergetalphanum){

   RUN_TEST_CASE(lexergetalphanum, testAlphanumCharArray);

   RUN_TEST_CASE(lexergetalphanum, testAlphanumCharArrayNumElement);

   RUN_TEST_CASE(lexergetalphanum, testBufferIteratorMoved);
}




TEST_GROUP(lexergetalphanumhaRollback);

TEST_GROUP_RUNNER(lexergetalphanumhaRollback){

    RUN_TEST_CASE(lexergetalphanumhaRollback, testBufferIteratorNotMoved);
    RUN_TEST_CASE(lexergetalphanumhaRollback, testAlphanumFoundButIteratorNotMoved)
}
