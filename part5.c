#include <stdio.h>
#include "part2.h"
#include "part3.h"
#include "part4.h"
#include "part5.h"

void part5 (void) {
   
   INTFLOAT a_tc1, a_tc2, a_tc3;
   INTFLOAT b_tc1, b_tc2, b_tc3;
   INTFLOAT c_tc1, c_tc2, c_tc3;
   float a_f1 = -1.0, a_f2 =  1.0, a_f3;
   float b_f1 = 1.0, b_f2 = 0.25, b_f3;
   float c_f1 = 4.0, c_f2 = -0.125, c_f3;

   printf("\n=========Part 5==========\n");

   extract_float(&a_tc1, a_f1);
   extract_float(&a_tc2, a_f2);
   add_two_floats(&a_tc1, &a_tc2, &a_tc3);

   printf("5a. 0xBF800000 and 0x3F800000 (-1 and +1)\n");
   a_f3 = get_float(&a_tc3);
   printf("  Sum:0x%08x  (%1.3f)\n", (unsigned int) * (unsigned int *) &a_f3, a_f3);

   extract_float(&b_tc1, b_f1);
   extract_float(&b_tc2, b_f2);
   add_two_floats(&b_tc1, &b_tc2, &b_tc3);
   
   printf("5b. 0x3F800000 and 0x3E800000 (1 + .25)\n");
   b_f3 = get_float(&b_tc3);
   printf("  Sum:0x%08x  (%1.3f)\n", (unsigned int) * (unsigned int *) &b_f3, b_f3);

   extract_float(&c_tc1, c_f1);
   extract_float(&c_tc2, c_f2);
   add_two_floats(&c_tc1, &c_tc2, &c_tc3);

   printf("5c. 0x40800000 and 0xBE000000 (4 and (-.125))\n");
   c_f3 = get_float(&c_tc3);
   printf("  Sum:0x%08x  (%1.3f)\n", (unsigned int) * (unsigned int *) &c_f3, c_f3);
   
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

