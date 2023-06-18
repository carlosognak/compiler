#include "../../exports.h"

TEST_GROUP(analyse_parameter);

TEST_GROUP_RUNNER(analyse_parameter){

   RUN_TEST_CASE(analyse_parameter, test_function_name_equals_main);

   RUN_TEST_CASE(analyse_parameter, test_function_with_two_parameters);
}

TEST_GROUP(analyse_function);
TEST_GROUP_RUNNER(analyse_function){

    RUN_TEST_CASE(analyse_function, test_ast_returned_not_null);
    RUN_TEST_CASE(analyse_function, test_function_name_not_null);
    RUN_TEST_CASE(analyse_function, test_function_name_equals_main);
    RUN_TEST_CASE(analyse_function, test_function_param_type_not_null);
    RUN_TEST_CASE(analyse_function, test_function_param_name_not_null);
    RUN_TEST_CASE(analyse_function, test_function_with_multi_params);
}

TEST_GROUP(analyse_returned_type);
TEST_GROUP_RUNNER(analyse_returned_type){

    RUN_TEST_CASE(analyse_returned_type, test_returned_type_equals_rien);
    RUN_TEST_CASE(analyse_returned_type, test_returned_type_equals_entier);
    RUN_TEST_CASE(analyse_returned_type, test_invalid_returned_type_error);
}
