#include "../include/libk/ctype.h"

#include <stdbool.h>

int isspace(int c) {
   switch (c) {
   case ' ':
   case '\f':
   case '\n':
   case '\t':
   case '\v':
   case '\r': return true;
   default: return false;
   }
}

int isdigit(int c) {
   if (c >= 48 && c <= 57) {
      return true;
   } else {
      return false;
   }
}

int isupper(int c) {
   if (c >= 'A' && c <= 'Z') {
      return true;
   } else {
      return false;
   }
}

int tolower(int c) {
   if (isupper(c)) {
      return c + 32;
   } else {
      return c;
   }
}