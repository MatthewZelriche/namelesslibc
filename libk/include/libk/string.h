#pragma once
#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Compliance Status: Should be fully compliant. */
void *memcpy(void *dest, void *src, size_t n);
/** Compliance Status: Should be fully compliant. */
size_t strlen(const char *s);
/** Compliance Status: Should be fully compliant for the "C" and "POSIX" Locales. */
int isspace(int c);

// ** Nonstandard.
char *strrev(char *str);

#ifdef __cplusplus
}
#endif