#include "../include/libk/stdlib.h"

#include <stdbool.h>
#include <stdint.h>

#include "../include/libk/string.h"

// TODO: Error checking.
long int strtol(const char *restrict nptr, char **restrict endptr, int base) {
   uint64_t position = 0;
   bool isNegative   = false;

   while (isspace(*(nptr + position))) { position++; }

   if (*(nptr + position) == '+') {
      position++;
   } else if (*(nptr + position) == '-') {
      isNegative = true;
      position++;
   }

   // Handle special case of base == 0;
   if (base == 0) {
      if (*(nptr + position) == '0' && (*(nptr + position + 1) == 'x' || *(nptr + position + 1) == 'X')) {
         base = 16;
         position++;
         position++;
      } else if (*(nptr + position) == '0' &&
                 !(*(nptr + position + 1) == 'x' || *(nptr + position + 1) == 'X')) {
         base = 8;
         position++;
      } else {
         base = 10;
      }
   }

   if (base == 16) {
      if (*(nptr + position) == '0' && (*(nptr + position + 1) == 'x' || *(nptr + position + 1) == 'X')) {
         position++;
         position++;
      }
   }

   int result = 0;
   while ((*(nptr + position) >= '0' && *(nptr + position) <= '9') ||
          (*(nptr + position) >= 'A' && *(nptr + position) <= 'Z') ||
          (*(nptr + position) >= 'a' && *(nptr + position) <= 'z')) {
      if ((*(nptr + position) >= '0' && *(nptr + position) <= '9')) {
         if (*(nptr + position) - '0' > base) {
            return result;
         }
         result = (result * base) + (*(nptr + position) - '0');
         position++;
      } else if ((*(nptr + position) >= 'A' && *(nptr + position) <= 'Z')) {
         if (*(nptr + position) - 'A' + 10 > base) {
            return result;
         }
         result = (result * base) + (*(nptr + position) - 'A' + 10);
         position++;
      } else if ((*(nptr + position) >= 'a' && *(nptr + position) <= 'z')) {
         if (*(nptr + position) - 'a' + 10 > base) {
            return result;
         }
         result = (result * base) + (*(nptr + position) - 'a' + 10);
         position++;
      }
   }
   return result;
}