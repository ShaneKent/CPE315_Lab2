#include <stdio.h>
#include "part2.h"
#include "part3.h"
#include "part4.h"
#include "part5.h"

void part5 (void) {
   
   INTFLOAT tc1, tc2, tc3;
   float f1 = -1.0, f2 =  1.0;
   
   extract_float(&tc1, f1);
   print_intfloat(&tc1);

   printf("\n");

   extract_float(&tc2, f2);
   print_intfloat(&tc2);

   printf("\n");

   add_two_floats(&tc1, &tc2, &tc3);
   print_intfloat(&tc3);
   
   printf("\n");

   return;
}

void add_two_floats(INTFLOAT_PTR a, INTFLOAT_PTR b, INTFLOAT_PTR result) {
   
   a->fraction = a->fraction >> 1;
   a->exponent = a->exponent + 1;

   b->fraction = b->fraction >> 1;
   b->exponent = b->exponent + 1;

   while (a->exponent > b->exponent) {
      b->exponent = b->exponent + 1;
      b->fraction = b->fraction >> 1;
   }
   
   while (b->exponent > a->exponent) {
      a->exponent = a->exponent + 1;
      a->fraction = a->fraction >> 1;
   }

   result->fraction = a->fraction + b->fraction;
   result->exponent = a->exponent;

   normalize(result);

   return;
}

