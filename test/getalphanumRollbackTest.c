#include "../lib/unity_fixture.h"

#include "../lib/unity.h"

#include "../buffer.h"*
#include "../lexer.h"


TEST_GROUP(lexergetalphanumhaRollback);

FILE* demo;
buffer_t buffer;

TEST_SETUP(lexergetalphanumhaRollback){
    demo = fopen("intech.txt", "r+");
    buf_init(&buffer, demo);
}
TEST_TEAR_DOWN(lexergetalphanumhaRollback){
    fclose(demo);
}

TEST(lexergetalphanumhaRollback, testAlphanumFoundButIteratorNotMoved){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("int",lexer_getalphanum_rollback(&buffer), 3);
    TEST_ASSERT_EQUAL(0, buffer.it);
}
TEST(lexergetalphanumhaRollback, testBufferIteratorNotMoved){

   TEST_ASSERT_EQUAL(3, strlen(lexer_getalphanum_rollback(&buffer)));
   TEST_ASSERT_EQUAL(0, buffer.it);
}
