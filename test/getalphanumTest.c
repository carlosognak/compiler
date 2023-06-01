#include "../lib/unity_fixture.h"

#include "../lib/unity.h"

#include "../buffer.h"

#include "../lexer.h"

#include "assert.h"

TEST_GROUP(LexerGetAlphanum);

static FILE* fp;
static buffer_t buffer;

TEST_SETUP(LexerGetAlphanum){

    fp = fopen("intech.txt", "r");
    if(fp == NULL){
        printf("Could not read the file");
        exit(1);
    }
    buf_init(&buffer, fp);
}

TEST_TEAR_DOWN(LexerGetAlphanum){
    fclose(fp);
}

TEST(LexerGetAlphanum, StringContentMatches){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("int", lexer_getalphanum(&buffer), 3);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("addition", lexer_getalphanum(&buffer), 8);

}
TEST(LexerGetAlphanum, BufferIteratorCurrentPosition){

    lexer_getalphanum(&buffer);

    TEST_ASSERT_EQUAL(4, buffer.it);

    lexer_getalphanum(&buffer);

    TEST_ASSERT_EQUAL(13, buffer.it);
}

TEST(LexerGetAlphanum, LengthOfStringMatches){

    TEST_ASSERT_EQUAL(3, strlen(lexer_getalphanum(&buffer)));
}

TEST(LexerGetAlphanum, TheBufferIteratorMoved){

    lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL(4, buffer.it);
}

TEST(LexerGetAlphanum, TextStartingWithUnderScore){
    fp = fopen("intech1.txt", "r");
    if(fp == NULL){
        printf("Could not read the file intech1.txt");
        exit(1);
    }
    buf_init(&buffer, fp);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("_number", lexer_getalphanum(&buffer), 8);
}

TEST(LexerGetAlphanum, TextContainsNumber){

   fp = fopen("variable_with_number.txt", "r+");

    if(fp == NULL){
        printf("Could not read the file variable_with_number.txt");
        exit(1);
    }

    buf_init(&buffer, fp);

    TEST_ASSERT_EQUAL_CHAR_ARRAY("int", lexer_getalphanum(&buffer), 3);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("number123",lexer_getalphanum(&buffer),8);
}
