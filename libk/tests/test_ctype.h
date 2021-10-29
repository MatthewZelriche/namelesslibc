#pragma once

#include "../include/libk/ctype.h"
#include "unity.h"

void isspace01_space(void) {
   int result = isspace(' ');
   TEST_ASSERT_TRUE(result);
}

void isspace02_special(void) {
   int result = isspace('\r');
   TEST_ASSERT_TRUE(result);
}

void isspace03_nonspace(void) {
   int result = isspace('g');
   TEST_ASSERT_FALSE(result);
}

void isdigit01_zero(void) {
   TEST_ASSERT_TRUE(isdigit('0'));
}

void isdigit02_middle(void) {
   TEST_ASSERT_TRUE(isdigit('4'));
}

void isdigit03_last(void) {
   TEST_ASSERT_TRUE(isdigit('9'));
}

void isdigit04_nondigit(void) {
   TEST_ASSERT_FALSE(isdigit('a'));
}