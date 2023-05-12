#include "../lib/unity_fixture.h"

#include "../lib/unity.h"

#include "../buffer.h"*
#include "../lexer.h"

TEST_GROUP(lexergetalphanum);

FILE* demo;
buffer_t buffer;

TEST_SETUP(lexergetalphanum){

    demo = fopen("intech.txt", "r+");

    buf_init(&buffer, demo);
}

TEST_TEAR_DOWN(lexergetalphanum){
    fclose(demo);
}

TEST(lexergetalphanum, testAlphanumCharArray){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("int", lexer_getalphanum(&buffer), 3);
}

TEST(lexergetalphanum, testAlphanumCharArrayNumElement){

    TEST_ASSERT_EQUAL(3, strlen(lexer_getalphanum(&buffer)));
}

TEST(lexergetalphanum, testBufferIteratorMoved){

    lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL(4, buffer.it);
}
