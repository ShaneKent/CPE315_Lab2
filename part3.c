#include <stdio.h>
#include "part2.h"
#include "part3.h"


float get_float(INTFLOAT_PTR x) {
   float f;
   int f_int;
   
   unsigned int fraction = x->fraction;
   unsigned int exponent = x->exponent;
   int sign;

   if (fraction == 0)
      return 0;

   sign = fraction & 0x80000000;

   if (sign == 0x80000000)
      fraction = ~fraction + 1;

   fraction = (fraction & 0x3FFFFFFF) >> 7;
   exponent = (exponent + 127 - 1) << 23;

   f_int = sign + exponent + fraction;

   f = (float) * (float *) &f_int;

   return f;
}

void part3 (void) {

   INTFLOAT tc1, tc2, tc3, tc4;
   float f1, f2, f3, f4;

   printf("=========Part 3==========\n");

   tc1.exponent = 3;
   tc1.fraction = 0x64000000;
   f1 = get_float(&tc1);
   printf("3a. Test case: 0x40C80000\n");
   printf("  Float: %f\n", f1);

   tc2.exponent = 8;
   tc2.fraction = 0xC0000000;
   f2 = get_float(&tc2);
   printf("3b. Test case: 0xC3000000\n");
   printf("  Float: %f\n", f2);

   tc3.exponent = -2;
   tc3.fraction = 0x40000000;
   f3 = get_float(&tc3);
   printf("3c. Test case: 0x3E000000\n");
   printf("  Float: %f\n", f3);

   tc4.exponent = -1;
   tc4.fraction = 0x55555580;
   f4 = get_float(&tc4);
   printf("3d. Test case: 0x3EAAAAAB\n");
   printf("  Float: %f\n", f4);

   printf("=========================\n\n");

   return;
}
