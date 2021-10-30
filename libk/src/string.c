#include "../include/libk/string.h"

#include "stdbool.h"

void *memcpy(void *restrict dest, void *restrict src, size_t n) {
   for (size_t i = 0; i < n; i++) { ((char *)dest)[i] = ((char *)src)[i]; }

   return dest;
}

size_t strlen(const char *s) {
   size_t byteCount = 0;
   size_t bufPos    = 0;
   while (true) {
      char charToProces = s[bufPos];
      if (charToProces != 0) {
         byteCount++;
      } else {
         break;
      }
      bufPos++;
   }
   return byteCount;
}

int strcmp(const char *s1, const char *s2) {
   size_t length = 0;
   if (strlen(s1) <= strlen(s2)) {
      length = strlen(s2);
   } else {
      length = strlen(s1);
   }

   for (int i = 0; i < length; i++) {
      if (s1[i] == s2[i]) {
         continue;
      } else if (s1[i] < s2[i]) {
         return -1;
      } else {
         return 1;
      }
   }

   return 0;
}

char *strrev(char *str) {
   int length = strlen(str);

   if (length == 0) {
      return str;
   }
   int forward = 0;
   int reverse = length - 1;

   while (forward < reverse) {
      char temp    = str[reverse];
      str[reverse] = str[forward];
      str[forward] = temp;
      forward++;
      reverse--;
   }

   return str;
}