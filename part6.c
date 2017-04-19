#include <stdio.h>
#include "part2.h"
#include "part3.h"
#include "part4.h"
#include "part5.h"
#include "part6.h"

void part6 (void) {

   INTFLOAT tc1, tc2, r;
   float f1 = 3.0, f2 = 1.0;
   float r1 = f1-f2;

   extract_float(&tc1, f1);
   extract_float(&tc2, f2);
   /*extract_float(&tc3, f3);
   extract_float(&tc4, f4);*/

   printf("=========Part 6==========\n");

   print_intfloat(&tc1);
   print_intfloat(&tc2);

   fsub(&tc1, &tc2, &r);
   printf("6a. 0x40400000 and 0x3F800000 (3 - 1)\n");
   /*print_intfloat(&tc1);
   print_intfloat(&tc2);*/
   print_intfloat(&r);
   print6(&r, r1);

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

void print6(INTFLOAT_PTR result, float resultD)
{
   printf("  Diff:0x%f (%f)\n", get_float(result), resultD);
}
