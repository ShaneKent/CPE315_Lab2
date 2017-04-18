#ifndef PART2
#define PART2

typedef struct _intfloat
{
   int exponent;
   int fraction;
} INTFLOAT, * INTFLOAT_PTR;

void extract_float(INTFLOAT_PTR x, float f);
void print_intfloat(INTFLOAT_PTR x);
void part2();

#endif
