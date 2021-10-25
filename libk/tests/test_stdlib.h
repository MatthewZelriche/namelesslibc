#pragma once

#include "../include/libk/stdlib.h"
#include "unity.h"

void strtol01_basicbase10(void) {
   int result = strtol("108731", NULL, 10);
   TEST_ASSERT_EQUAL_INT(108731, result);
}

void strtol02_basicnegativebase10(void) {
   int result = strtol("-465", NULL, 10);
   TEST_ASSERT_EQUAL_INT(-465, result);
}

void strtol03_base0decimal(void) {
   int result = strtol("2707", NULL, 0);
   TEST_ASSERT_EQUAL_INT(2707, result);
}

void strtol04_base0hex(void) {
   int result = strtol("0xF4C", NULL, 0);
   TEST_ASSERT_EQUAL_INT(3916, result);
}

void strtol05_base0octal(void) {
   int result = strtol("-042", NULL, 0);
   TEST_ASSERT_EQUAL_INT(-34, result);
}

void strtol06_base2(void) {
   int result = strtol("11010", NULL, 2);
   TEST_ASSERT_EQUAL_INT(26, result);
}

void strtol07_base16noleadingchars(void) {
   int result = strtol("ff17b", NULL, 16);
   TEST_ASSERT_EQUAL_INT(1044859, result);
}

void strtol08_base36mixedcase(void) {
   int result = strtol("Z1hT7", NULL, 36);
   TEST_ASSERT_EQUAL_INT(58856299, result);
}

void strtol09_leadingwhitespace(void) {
   int result = strtol("     \n   \t\r -517", NULL, 10);
   TEST_ASSERT_EQUAL_INT(-517, result);
}

void strtol10_invalidcharptrnullterm(void) {
   char* result2;
   int result = strtol("1444", &result2, 10);
   TEST_ASSERT_EQUAL_INT(1444, result);
   TEST_ASSERT_EQUAL_CHAR('\0', *result2);
}

void strtol11_invalidcharptr(void) {
   char* result2 = NULL;
   int result    = strtol("-0.2f", &result2, 10);
   TEST_ASSERT_EQUAL_INT(0, result);
   TEST_ASSERT_EQUAL_CHAR('.', *result2);
}

void strtol12_nodigits(void) {
   char* result2    = NULL;
   const char* test = "       tfgh";
   int result       = strtol(test, &result2, 10);
   TEST_ASSERT_EQUAL_INT(0, result);
   TEST_ASSERT_EQUAL_PTR(test + 7, result2);
}

void abs01_zero(void) {
   TEST_ASSERT_EQUAL_INT(0, abs(0));
}

void abs02_pos(void) {
   TEST_ASSERT_EQUAL_INT(578, abs(578));
}

void abs03_neg(void) {
   TEST_ASSERT_EQUAL_INT(467, abs(-467));
}

void itoa01(void) {
   char input[22];
   itoa(1567, input, 10);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("1567", input, 5);
}

void itoa02(void) {
   char input[22];
   itoa(0, input, 10);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("0", input, 2);
}

void itoa03(void) {
   char input[22];
   itoa(-401, input, 10);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("-401", input, 5);
}

void itoa04(void) {
   char input[22];
   itoa(242, input, 16);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("F2", input, 3);
}

void itoa05(void) {
   char input[22];
   itoa(-57114, input, 16);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("FFFF20E6", input, 9);
}

void itoa06(void) {
   char input[22];
   itoa(28926658, input, 36);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("H7ZYA", input, 6);
}
