#include <stdio.h>
#include "part2.h"

INTFLOAT makeIntfloat(int exponent, int fraction)
{
   INTFLOAT i;
   i.exponent = exponent;
   i.fraction = fraction;

   return i;
}


void extract_float(INTFLOAT_PTR x, float f)
{
   unsigned int exponent, fraction, i;

   i = (unsigned int) * (unsigned int *) &f;
   exponent = i & 0x7F800000;
   exponent = exponent - 127;
   printf("%08x\n", exponent);
}

void part2()
{
   INTFLOAT tc1 = makeIntfloat(0, 0);
   INTFLOAT tc2 = makeIntfloat(0, 0);
   INTFLOAT tc3 = makeIntfloat(0, 0);
   INTFLOAT tc4 = makeIntfloat(0, 0);
   float f1 = 6.25, f2 = -128.0, f3 = 0.125, f4 = 0.33333334;
   extract_float(&tc1, f1);
   extract_float(&tc2, f2);
   extract_float(&tc3, f3);
   extract_float(&tc4, f4);
}
