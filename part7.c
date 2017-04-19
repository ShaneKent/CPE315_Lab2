#include <stdio.h>
#include "part2.h"
#include "part3.h"
#include "part4.h"
#include "part7.h"

void part7 (void) {

   float a, b;

   a = fmul(2.5, 2.5);
   b = fmul(-15, 4096);

   printf("=========Part 7==========\n");
   printf("7a. 0x40200000 and 0x40200000 (2.5 x 2.5)\n");
   printf("  Product:0x%08x  (%.3f)\n", (unsigned int) * (unsigned int *) &a, a);
   printf("7b. 0xC1700000 and 0x45800000 (-15 x 4096)\n");
   printf("  Product:0x%08x  (%.3f)\n", (unsigned int) * (unsigned int *) &b, b);
   printf("=========================\n\n");

   return;
}

float fmul (float a, float b) {
   INTFLOAT result, a_if, b_if;

   extract_float(&a_if, a);
   extract_float(&b_if, b);

   result.fraction = ((long) a_if.fraction) * ((long) b_if.fraction) >> 32;
   result.exponent = a_if.exponent + b_if.exponent + 1;
   
   normalize(&result);

   return get_float(&result);
}
