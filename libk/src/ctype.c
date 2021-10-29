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