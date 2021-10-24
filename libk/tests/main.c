#include "test_stdlib.h"
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
   RUN_TEST(strlen01_basictest);
   RUN_TEST(strlen02_emptystring);
   RUN_TEST(strlen03_onechar);
   RUN_TEST(strlen04_longstring);
   RUN_TEST(strlen05_controlcharacter);

   RUN_TEST(isspace01_space);
   RUN_TEST(isspace02_special);
   RUN_TEST(isspace03_nonspace);

   RUN_TEST(memcpy01_strings);
   RUN_TEST(memcpy02_copynothing);
   RUN_TEST(memcpy03_copypartial);
   RUN_TEST(memcpy04_structs);

   RUN_TEST(strtol01_basicbase10);
   RUN_TEST(strtol02_basicnegativebase10);
   RUN_TEST(strtol03_base0decimal);
   RUN_TEST(strtol04_base0hex);
   RUN_TEST(strtol05_base0octal);
   RUN_TEST(strtol06_base2);
   RUN_TEST(strtol07_base16noleadingchars);
   RUN_TEST(strtol08_base36mixedcase);
   RUN_TEST(strtol09_leadingwhitespace);
   RUN_TEST(strtol10_invalidcharptrnullterm);
   RUN_TEST(strtol11_invalidcharptr);
   RUN_TEST(strtol12_nodigits);
   return UNITY_END();
}