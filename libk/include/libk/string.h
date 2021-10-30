#pragma once
#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Compliance Status: Should be fully compliant. */
void *memcpy(void *dest, void *src, size_t n);
/** Compliance Status: Should be fully compliant. */
size_t strlen(const char *s);
/** Compliance Status: Should be fully compliant. */
int strcmp(const char *s1, const char *s2);

// ** Nonstandard.
char *strrev(char *str);

#ifdef __cplusplus
}
#endif