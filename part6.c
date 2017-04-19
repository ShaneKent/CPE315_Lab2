#include <stdio.h>
#include "part2.h"
#include "part3.h"
#include "part4.h"
#include "part5.h"
#include "part6.h"

void part6 (void) {

   INTFLOAT t1a, t2a, t1b, t2b, t1c, t2c, r;
   float f1 = 3.0, f2 = 1.0,f3 = -1.0, f4 = 2.0; 

   extract_float(&t1a, f1);
   extract_float(&t2a, f2);
   extract_float(&t1b, f1);
   extract_float(&t2b, f3);
   extract_float(&t1c, f4);
   extract_float(&t2c, f4);

   printf("=========Part 6==========\n");

   fsub(&t1a, &t2a, &r);
   printf("6a. 0x40400000 and 0x3F800000 (3 - 1)\n");
   print6(&r);

   fsub(&t1b, &t2b, &r);
   printf("6b. 0x40400000 and 0xBF800000 (3 - (-1) )\n");
   print6(&r);

   fsub(&t1c, &t2c, &r);
   printf("6c. 0x40000000 and 0x40000000\n");
   print6(&r);

   printf("=========================\n\n");

   return;
}

void fsub(INTFLOAT_PTR a, INTFLOAT_PTR b, INTFLOAT_PTR result)
{
   a->fraction = a->fraction >> 1;
   a->exponent = a->exponent + 1;

   b->fraction = b->fraction >> 1;
   b->exponent = b->exponent + 1;

   while (a->exponent < b->exponent)
   {
      a->fraction = a->fraction >> 1;
      a->exponent = a->exponent + 1;
   }

   while (a->exponent > b->exponent)
   {
      b->fraction = b->fraction >> 1;
      b->exponent = b->exponent + 1;
   }

   result->fraction = a->fraction - b->fraction;
   result->exponent = a->exponent;

   normalize(result);

   return;
}

void print6(INTFLOAT_PTR result)
{
   float r = get_float(result);
   unsigned int k = (unsigned int) * (unsigned int *) &r;
   printf("  Diff:0x%08x (%1.3f)\n", k, r);
}
