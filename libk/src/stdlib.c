#include "../include/libk/stdlib.h"

#include <stdbool.h>
#include <stdint.h>

#include "../include/libk/ctype.h"
#include "../include/libk/string.h"

// TODO: Error checking.
long int strtol(const char *nptr, char **endptr, int base) {
   uint64_t position = 0;
   bool isNegative   = false;
   bool noDigits     = true;

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
      noDigits = false;
      if ((*(nptr + position) >= '0' && *(nptr + position) <= '9')) {
         if (*(nptr + position) - '0' > base) {
            break;
         }
         result = (result * base) + (*(nptr + position) - '0');
         position++;
      } else if ((*(nptr + position) >= 'A' && *(nptr + position) <= 'Z')) {
         if (*(nptr + position) - 'A' + 10 > base) {
            break;
         }
         result = (result * base) + (*(nptr + position) - 'A' + 10);
         position++;
      } else if ((*(nptr + position) >= 'a' && *(nptr + position) <= 'z')) {
         if (*(nptr + position) - 'a' + 10 > base) {
            break;
         }
         result = (result * base) + (*(nptr + position) - 'a' + 10);
         position++;
      }
   }

   if (endptr != NULL) {
      if (noDigits) {
         *endptr = nptr;
      }
      *endptr = ((uint8_t *)nptr + position);
   }

   if (isNegative) {
      return -result;
   } else {
      return result;
   }
}

int abs(int val) {
   return __builtin_abs(val);
}

char *itoa(int value, char *str, int base) {
   bool isNegative = false;
   uint8_t bufPos  = 0;

   if (value == 0) {
      str[bufPos] = '0';
      bufPos++;
   }

   if (base == 10) {
      if (value < 0) {
         isNegative = true;
      }
   }

   unsigned int convertedVal = 0;
   if (base != 10) {
      convertedVal = (unsigned int)value;
   } else {
      convertedVal = (unsigned int)abs(value);
   }

   while (convertedVal > 0) {
      uint8_t digit = convertedVal % base;
      char code     = digit + '0';

      if (code > '9') {
         code += 7;
      }

      str[bufPos] = code;
      bufPos++;

      convertedVal /= base;
   }

   if (isNegative) {
      str[bufPos] = '-';
      bufPos++;
   }

   str[bufPos] = '\0';
   strrev(str);
   return str;
}