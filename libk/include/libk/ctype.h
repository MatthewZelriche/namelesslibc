#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/** Compliance Status: Should be fully compliant for the "C" and "POSIX" Locales. */
int isspace(int c);

/** Compliance Status: Should be fully compliant for the "C" and "POSIX" Locales. */
int isdigit(int c);

int isupper(int c);
int tolower(int c);

#ifdef __cplusplus
}
#endif