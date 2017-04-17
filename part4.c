#include <stdio.h>
#include <stdlib.h>
#include "part2.h"
#include "part3.h"
#include "part4.h"

void normalize(INTFLOAT_PTR x){

   int msb;
   int nsb;
   
   int sign = (x->fraction & 0x80000000) >> 31;

   if (x->fraction == 0x00000000)
      return;
   
   msb = (0x80000000 & x->fraction) >> 31;
   nsb = (0x40000000 & x->fraction) >> 30;

   while (msb == nsb) {
      
      if (msb == 0 || sign == 1) {
         x->fraction = (unsigned int) x->fraction << 1;
         x->exponent = x->exponent - 1;
      } else {
         x->fraction = (unsigned int) x->fraction >> 1;
         x->exponent = x->exponent + 1;
      }
      
      msb = (0x80000000 & x->fraction) >> 31;
      nsb = (0x40000000 & x->fraction) >> 30;
            
   }

   return;
}

void print_exp_fraction(INTFLOAT_PTR x) {

   printf("Exp = %d, Frac = 0x%08x\n", x->exponent, x->fraction);

   return;
}

void part4 (void) {
   
   INTFLOAT tc1, tc2, tc3, tc4;

   printf("=========Part 4==========\n");

   tc1.exponent = 0x00000001;
   tc1.fraction = 0x40000000;
   
   normalize(&tc1);
   printf("4a. ");
   print_exp_fraction(&tc1);

   tc2.exponent = 0x00000000;
   tc2.fraction = 0x00200000;

   normalize(&tc2);
   printf("4b. ");
   print_exp_fraction(&tc2);
   
   tc3.exponent = 0x0000000C;
   tc3.fraction = 0xFFC00000;

   normalize(&tc3);
   printf("4c. ");
   print_exp_fraction(&tc3);
   
   tc4.exponent = 0xFFFFFFF8;
   tc4.fraction = 0x02000000;

   normalize(&tc4);
   printf("4d. ");
   print_exp_fraction(&tc4);
   
   printf("=========================\n");

   return;
}
