#include "../../lib/unity_fixture.h"
#include "../../lib/unity.h"

TEST_GROUP(test_group_analyse_parameter);

TEST_GROUP_RUNNER(test_group_analyse_parameter){

   RUN_TEST_CASE(test_group_analyse_parameter,test_function_name_equals_main);
   RUN_TEST_CASE(test_group_analyse_parameter,test_function_param_type_is_entier);
   RUN_TEST_CASE(test_group_analyse_parameter,test_first_function_param_name_equals_nbr);
   RUN_TEST_CASE(test_group_analyse_parameter,test_second_param_type_is_entier);
   RUN_TEST_CASE(test_group_analyse_parameter, test_third_param_type_is_entier);
   RUN_TEST_CASE(test_group_analyse_parameter,test_function_with_two_parameters);
}

TEST_GROUP(test_group_analyse_function);
TEST_GROUP_RUNNER(test_group_analyse_function){

    RUN_TEST_CASE(test_group_analyse_function, test_ast_returned_not_null);
    RUN_TEST_CASE(test_group_analyse_function, test_function_name_not_null);
    RUN_TEST_CASE(test_group_analyse_function, test_function_name_equals_main);
    RUN_TEST_CASE(test_group_analyse_function, test_function_param_type_not_null);
    RUN_TEST_CASE(test_group_analyse_function, test_function_param_name_not_null);
    RUN_TEST_CASE(test_group_analyse_function, test_function_with_multi_params);
}

TEST_GROUP(analyse_returned_type);
TEST_GROUP_RUNNER(analyse_returned_type){

    RUN_TEST_CASE(analyse_returned_type, test_returned_type_equals_rien);
    RUN_TEST_CASE(analyse_returned_type, test_returned_type_equals_entier);
}
TEST_GROUP(test_group_function_body);
TEST_GROUP_RUNNER(test_group_function_body){

   RUN_TEST_CASE(test_group_function_body, test_function_body_is_not_empty)
}
