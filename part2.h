#ifndef PART2
#define PART2

typedef struct _intfloat
{
   int exponent;
   int fraction;
} INTFLOAT, *INTFLOAT_PTR;

INTFLOAT makeIntfloat(int exponent, int fraction);
void extract_float(INTFLOAT_PTR x, float f);
void part2();

#endif
