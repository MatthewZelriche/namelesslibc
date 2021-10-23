#include "test_string.h"
#include "unity.h"

void setUp(void) {
   // set stuff up here
}

void tearDown(void) {
   // clean stuff up here
}

// not needed when using generate_test_runner.rb
int main(void) {
   UNITY_BEGIN();
   RUN_TEST(strlen01);
   return UNITY_END();
}