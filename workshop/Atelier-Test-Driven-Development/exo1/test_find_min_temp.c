#include "unity.h"
#include "find_min_temp.h"

void setUp(void) {
    
}

void tearDown(void) {
    // clean stuff up here
}

void test_enter_arg(void) {

	TEST_ASSERT_EQUAL_INT_MESSAGE( 0, find_min_temp(NULL, 0), "Aucun argument passer");
	TEST_ASSERT_EQUAL_INT_MESSAGE( -42, find_min_temp(NULL, 11000), "Inferieur a 10k");
}

void test_function_should_doAlsoDoBlah(void) {
    //more test stuff
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
	//RUN_TEST(setUp);
    RUN_TEST(test_enter_arg);
    //RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}
