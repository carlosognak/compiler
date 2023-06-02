/*
#include "../lib/unity_fixture.h"

#include "../lib/unity.h"

#include "../buffer.h"*
#include "../lexer.h"


TEST_GROUP(lexergetalphanumhaRollback);

FILE* fp;
buffer_t buffer;

TEST_SETUP(lexergetalphanumhaRollback){
    fp = fopen("intech.txt", "r+");

    if(fp == NULL){
        printf("Could not read the file");
        exit(1);
    }
    buf_init(&buffer, fp);
}
TEST_TEAR_DOWN(lexergetalphanumhaRollback){

    fclose(fp);
}

TEST(lexergetalphanumhaRollback, testAlphanumFoundButIteratorNotMoved){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("int",lexer_getalphanum_rollback(&buffer), 3);
    TEST_ASSERT_EQUAL(0, buffer.it);
}
TEST(lexergetalphanumhaRollback, testBufferIteratorNotMoved){

   TEST_ASSERT_EQUAL(3, strlen(lexer_getalphanum_rollback(&buffer)));
   TEST_ASSERT_EQUAL(0, buffer.it);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("int",lexer_getalphanum_rollback(&buffer), 3);
   TEST_ASSERT_EQUAL(0, buffer.it);

}

*/
