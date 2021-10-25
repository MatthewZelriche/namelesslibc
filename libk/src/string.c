#include "../include/libk/string.h"

#include "stdbool.h"

void *memcpy(void *restrict dest, void *restrict src, size_t n) {
   for (int i = 0; i < n; i++) { ((char *)dest)[i] = ((char *)src)[i]; }

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