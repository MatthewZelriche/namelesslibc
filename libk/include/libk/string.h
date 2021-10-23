#pragma once
#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

void *memcpy(void *dest, void *src, size_t n);
size_t strlen(const char *s);
int isspace(int c);

#ifdef __cplusplus
}
#endif