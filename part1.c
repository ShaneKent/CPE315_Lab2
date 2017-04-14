#include <stdio.h>
#include "part1.h"

void part1 (void) {
   unsigned int test1 = umultiply((unsigned int) 0x0001, (unsigned int) 0x0001);
   unsigned int test2 = umultiply((unsigned int) 0x0001, (unsigned int) 0xFFFF);
   unsigned int test3 = umultiply((unsigned int) 0x8000, (unsigned int) 0x0001);
   unsigned int test4 = umultiply((unsigned int) 0x4000, (unsigned int) 0x4000);
   unsigned int test5 = umultiply((unsigned int) 0x8000, (unsigned int) 0x8000);

   printf("=========Part 1==========\n");
   printf("1a. a=0x0001, b=0x0001 c=0x%08x\n", test1);
   printf("1b. a=0x0001, b=0xFFFF c=0x%08x\n", test2);
   printf("1c. a=0x8000, b=0x0001 c=0x%08x\n", test3);
   printf("1d. a=0x4000, b=0x4000 c=0x%08x\n", test4);
   printf("1e. a=0x8000, b=0x8000 c=0x%08x\n", test5);
   printf("=========================\n\n");
   
   return;
}

/*
 * a is the multiplier.
 * b is the multiplicand.
 *
 * Multiplicand
 * x Multiplier
 * ------------
 *      Product
 */
unsigned int umultiply (unsigned int a, unsigned int b) {
   unsigned int c = 0;
   
   while (a > 0) {
      if (a & 1)
         c = c + b;
      b = b << 1;
      a = a >> 1;
   }

   return c;
}
