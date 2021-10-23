#pragma once

#include "../include/libk/string.h"
#include "unity.h"

void strlen01(void) {
   TEST_ASSERT_TRUE(strlen("This") == 4);
}