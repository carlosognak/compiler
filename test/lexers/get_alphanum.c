#include "../../exports.h"

TEST_GROUP(alphanum);

static FILE* fp;
static buffer_t buffer;

TEST_SETUP(alphanum){

    fp = fopen("intech.txt", "r");
    if(fp == NULL){
        printf("Could not read the file");
        exit(1);
    }
    buf_init(&buffer, fp);
}

TEST_TEAR_DOWN(alphanum){
    fclose(fp);
}

TEST(alphanum,test_string_alphanum_found_success){

    TEST_ASSERT_EQUAL_CHAR_ARRAY("int", lexer_getalphanum(&buffer), 3);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("addition", lexer_getalphanum(&buffer), 8);

}
TEST(alphanum,test_iterator_is_in_correct_position){

    lexer_getalphanum(&buffer);

    TEST_ASSERT_EQUAL(3, buffer.it);

    lexer_getalphanum(&buffer);

    TEST_ASSERT_EQUAL(12, buffer.it);
}

TEST(alphanum, test_length_of_alphanum){

    TEST_ASSERT_EQUAL(3, strlen(lexer_getalphanum(&buffer)));
}

TEST(alphanum, test_iterator_has_moved){

    lexer_getalphanum(&buffer);
    TEST_ASSERT_EQUAL(3, buffer.it);
}

TEST(alphanum, test_alphanum_with_underscore){
    fp = fopen("intech1.txt", "r");
    if(fp == NULL){
        printf("Could not read the file intech1.txt");
        exit(1);
    }
    buf_init(&buffer, fp);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("_number", lexer_getalphanum(&buffer), 8);
}

TEST(alphanum, test_alphanum_is_a_number){

   fp = fopen("variable_with_number.txt", "r+");

    if(fp == NULL){
        printf("Could not read the file variable_with_number.txt");
        exit(1);
    }

    buf_init(&buffer, fp);

    TEST_ASSERT_EQUAL_CHAR_ARRAY("int", lexer_getalphanum(&buffer), 3);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("number123",lexer_getalphanum(&buffer),8);
}
