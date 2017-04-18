#include <stdio.h>
#include "part2.h"
#include "part3.h"

void extract_float(INTFLOAT_PTR x, float f)
{  
   int sign;
   int exponent;
   int fraction;

   unsigned int i = (unsigned int) * (unsigned int *) &f;
   
   sign     = (i & 0x80000000) >> 31;
   exponent = (i & 0x7F800000) >> 23;
   fraction = (i & 0x007FFFFF) << 7;

   fraction |= 0x40000000;
   
   if (sign == 1)
      fraction = ~fraction + 1; 

   x->fraction = fraction;
   x->exponent = exponent - 127 + 1;

   return;
}

void print_intfloat(INTFLOAT_PTR x)
{
   printf("  Float: %f\n", get_float(x));
   printf("  Exponent: %d\n", x->exponent);
   printf("  Fraction: 0x%08x\n", x->fraction);

   return;
}

void part2()
{
   INTFLOAT tc1, tc2, tc3, tc4;

   printf("=========Part 2==========\n");

   printf("2a. Test case: 0x40C80000\n");
   extract_float(&tc1, 6.25);
   print_intfloat(&tc1);

   printf("2b. Test case: 0xC3000000\n");
   extract_float(&tc2, -128.0);
   print_intfloat(&tc2);

   printf("2c. Test case: 0x3e000000\n");
   extract_float(&tc3, 0.125);
   print_intfloat(&tc3);
   
   printf("2d. Test case: 0x3EAAAAAB\n");
   extract_float(&tc4, 0.33333334);
   print_intfloat(&tc4);

   printf("=========================\n\n");

   return;
}
