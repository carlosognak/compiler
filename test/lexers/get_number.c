#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../buffer.h"

#include <stdio.h>

TEST_GROUP(number);

FILE *fp;

buffer_t buffer;

TEST_SETUP(number){

    fp = fopen("./programs/number.txt", "r+");

    if(fp == NULL){
        printf("Could not read the file number.txt for test_group_lexer_getnumber");
        exit(1);
    }
    buf_init(&buffer, fp);
}

TEST_TEAR_DOWN(number){
    fclose(fp);
}

TEST(number, test_find_all_numbers_in_the_buffer){

    TEST_ASSERT_EQUAL(125, lexer_getnumber(&buffer));

    TEST_ASSERT_EQUAL(18, buffer.it);

    long number = lexer_getnumber(&buffer);

    TEST_ASSERT_NOT_EQUAL(19, buffer.it);

    TEST_ASSERT_EQUAL(24, buffer.it);

    TEST_ASSERT_EQUAL(234, number);

    TEST_ASSERT_EQUAL(13, lexer_getnumber(&buffer));

    TEST_ASSERT_EQUAL(20, lexer_getnumber(&buffer));
}
