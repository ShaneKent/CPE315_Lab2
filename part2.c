#include <stdio.h>
#include "part2.h"

INTFLOAT make_empty_intfloat (void)
{
   INTFLOAT i;
   i.exponent = 0;
   i.fraction = 0;

   return i;
}

void extract_float(INTFLOAT_PTR x, float f)
{  
   int sign;
   int exponent;
   int fraction;

   unsigned int i = (unsigned int) * (unsigned int *) &f;
   
   sign = (i & 0x80000000) >> 31;
   exponent = (int) (i & 0x7F800000) >> 23;
   exponent = exponent - 127;
   fraction = (int) (i & 0x007FFFFF) + 0x00800000;
   if (sign == 1)
      fraction = ~fraction;
   
   x->exponent = exponent;
   x->fraction = fraction;

   return;
}

void print_intfloat(INTFLOAT_PTR x, float f)
{
   printf("  Float: %f\n", f);
   printf("  Exponent: %d\n", x->exponent);
   printf("  Fraction: 0x%08x\n", x->fraction);

   return;
}

void part2()
{
   INTFLOAT tc1, tc2, tc3, tc4;
   float f1, f2, f3, f4;

   printf("=========Part 2==========\n");

   printf("2a. Test case: 0x40C80000\n");
   tc1 = make_empty_intfloat();
   f1 = 6.25;
   extract_float(&tc1, f1);
   print_intfloat(&tc1, f1);

   printf("2b. Test case: 0xC3000000\n");
   tc2 = make_empty_intfloat();
   f2 = -128.0;
   extract_float(&tc2, f2);
   print_intfloat(&tc2, f2);

   printf("2c. Test case: 0x3e000000\n");
   tc3 = make_empty_intfloat();
   f3 = 0.125;
   extract_float(&tc3, f3);
   print_intfloat(&tc3, f3);
   
   printf("2d. Test case: 0x3EAAAAAB\n");
   tc4 = make_empty_intfloat();
   f4 = 0.33333334;
   extract_float(&tc4, f4);
   print_intfloat(&tc4, f4);

   printf("=========================\n\n");

   return;
}
