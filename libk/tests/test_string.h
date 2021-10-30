#pragma once

#include "../include/libk/string.h"
#include "unity.h"

void strlen01_basictest(void) {
   int result = strlen("Basic Test");
   TEST_ASSERT_EQUAL_INT(10, result);
}

void strlen02_emptystring(void) {
   int result = strlen("");
   TEST_ASSERT_EQUAL_INT(0, result);
}

void strlen03_onechar(void) {
   int result = strlen("a");
   TEST_ASSERT_EQUAL_INT(1, result);
}

void strlen04_longstring(void) {
   int result = strlen(
      "This is a long message. It is very long. But it doesn't need to be too long. It is only as "
      "long as it needs to be, which is exactly as long as it currently is.");
   TEST_ASSERT_EQUAL_INT(159, result);
}

void strlen05_controlcharacter(void) {
   int result = strlen(" \n\r");
   TEST_ASSERT_EQUAL_INT(3, result);
}

void memcpy01_strings(void) {
   char string2[10] = "Basic Test";
   char string1[10] = "asdfghjkl;";
   void* result     = memcpy(string1, string2, 10);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("Basic Test", string1, 10);
   TEST_ASSERT_EQUAL_PTR(&string1, result);
}

void memcpy02_copynothing(void) {
   char string2[10] = "Basic Test";
   char string1[10] = "Different.";
   void* result     = memcpy(string1, string2, 0);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("Different.", string1, 10);
   TEST_ASSERT_EQUAL_PTR(&string1, result);
}

void memcpy03_copypartial(void) {
   char string2[12] = "A Basic Test";
   char string1[12] = "Differently.";
   void* result     = memcpy(string1, string2, 5);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("A Basrently.", string1, 12);
   TEST_ASSERT_EQUAL_PTR(&string1, result);
}

typedef struct TestStruct {
   uint32_t myArray[4];
   char myChar;
   int myInt;
} TestStruct;

void memcpy04_structs(void) {
   TestStruct struct2 = {{6, 25475835, 0, 35}, 'c', -45};
   TestStruct struct1 = {{0, 0, 1, 2}, 'd', 40};
   void* result       = memcpy((void*)&struct1, (void*)&struct2, sizeof(TestStruct));

   uint32_t correctArray[4] = {6, 25475835, 0, 35};
   TEST_ASSERT_EQUAL_UINT32_ARRAY(correctArray, struct1.myArray, 4);
   TEST_ASSERT_EQUAL_CHAR('c', struct1.myChar);
   TEST_ASSERT_EQUAL_INT(-45, struct1.myInt);
   TEST_ASSERT_EQUAL_PTR(&struct1, result);
}

void strcmp01_equal() {
   int result = strcmp("Spaghetti", "Spaghetti");
   TEST_ASSERT_EQUAL_INT(0, result);
}

void strcmp02_differentCase() {
   int result = strcmp("Spaghetti", "spaghetti");
   TEST_ASSERT_EQUAL_INT(-1, result);
}

void strcmp03_greaterThan() {
   int result = strcmp("spaghetti", "dog");
   TEST_ASSERT_EQUAL_INT(1, result);
}

void strcmp04_lessThan() {
   int result = strcmp("cat", "dog");
   TEST_ASSERT_EQUAL_INT(-1, result);
}

void strcmp05() {
   int result = strcmp("dog", "dog2");
   TEST_ASSERT_EQUAL_INT(-1, result);
}

void strcmp06() {
   int result = strcmp("dog3", "dog");
   TEST_ASSERT_EQUAL_INT(1, result);
}

void strrev01_oddnumber(void) {
   char input[6] = "Test!";
   strrev(input);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("!tseT", input, 6);
}

void strrev02_evennumber(void) {
   char input[13] = "This a test\n";
   strrev(input);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("\ntset a sihT", input, 13);
}

void strrev03_empty(void) {
   char input[6] = "";
   strrev(input);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("", input, 1);
}

void strrev04_onechar(void) {
   char input[6] = "a";
   strrev(input);
   TEST_ASSERT_EQUAL_CHAR_ARRAY("a", input, 2);
}