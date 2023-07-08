#include <stdio.h>

#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"
#include "../../lexer.h"
#include "../../buffer.h"


TEST_GROUP(alphanum_rollback);

static FILE* fp;
static buffer_t buffer;

TEST_SETUP(alphanum_rollback){
    fp = fopen("./programs/intech.txt", "r+");

    if(fp == NULL){
        printf("Could not read the file intech.txt for test_group_alphanum_rollback");
        exit(1);
    }
    buf_init(&buffer, fp);
}
TEST_TEAR_DOWN(alphanum_rollback){

    fclose(fp);
}

TEST(alphanum_rollback, test_iterator_has_not_moved){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("int",lexer_getalphanum_rollback(&buffer), 3);
    TEST_ASSERT_EQUAL(0, buffer.it);
}
TEST(alphanum_rollback, test_alphanum_length_after_rollback){

   TEST_ASSERT_EQUAL(3, strlen(lexer_getalphanum_rollback(&buffer)));
   TEST_ASSERT_EQUAL(0, buffer.it);
}
