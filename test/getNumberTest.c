#include "../lib/unity_fixture.h"
#include "../buffer.h"


TEST_GROUP(GetNumberLexer);

FILE *fp;

buffer_t buffer;

TEST_SETUP(GetNumberLexer){

    fp = fopen("number.txt", "r+");

    if(fp == NULL){
        printf("Could not read the file in write mode");
        exit(1);
    }
    buf_init(&buffer, fp);
}

TEST_TEAR_DOWN(GetNumberLexer){
    fclose(fp);
}

TEST(GetNumberLexer, FindAllNumber){

    TEST_ASSERT_EQUAL(125, lexer_getnumber(&buffer));

    TEST_ASSERT_EQUAL(19, buffer.it);

    long number = lexer_getnumber(&buffer);

    TEST_ASSERT_NOT_EQUAL(19, buffer.it);

    TEST_ASSERT_EQUAL(25, buffer.it);

    TEST_ASSERT_EQUAL(234, number);

    TEST_ASSERT_EQUAL(13, lexer_getnumber(&buffer));

    TEST_ASSERT_EQUAL(20, lexer_getnumber(&buffer));

    TEST_ASSERT_EQUAL(100, lexer_getnumber(&buffer));
}
