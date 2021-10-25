#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/** Compliance Status:
 * Should be mostly compliant with the standard, except for the following:
 * 1. Does not handle overflow or underflow.
 * 2. Does not write to errno.
 */
long int strtol(const char *nptr, char **endptr, int base);

/** Compliance Status: Should be fully compliant. */
int abs(int val);

/** Nonstandard */
char *itoa(int value, char *str, int base);

#ifdef __cplusplus
}
#endif