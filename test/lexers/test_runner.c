#include "../../exports.h"

TEST_GROUP(alphanum);

TEST_GROUP_RUNNER(alphanum){

   RUN_TEST_CASE(alphanum, test_string_alphanum_found_success);

   RUN_TEST_CASE(alphanum, test_length_of_alphanum);

   RUN_TEST_CASE(alphanum, test_iterator_has_moved);

   RUN_TEST_CASE(alphanum, test_alphanum_with_underscore);

   RUN_TEST_CASE(alphanum, test_alphanum_is_a_number);

   RUN_TEST_CASE(alphanum, test_iterator_is_in_correct_position);
}

TEST_GROUP(alphanum_rollback);

TEST_GROUP_RUNNER(alphanum_rollback){

    RUN_TEST_CASE(alphanum_rollback, test_iterator_has_not_moved);
    RUN_TEST_CASE(alphanum_rollback, test_alphanum_length_after_rollback)
}

TEST_GROUP(number);

TEST_GROUP_RUNNER(number){
    RUN_TEST_CASE(number, test_find_all_numbers_in_the_buffer);
}

