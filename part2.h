#ifndef PART2
#define PART2

typedef struct _intfloat * INTFLOAT_PTR;

typedef struct _intfloat
{
   int exponent;
   int fraction;
} INTFLOAT;

INTFLOAT make_empty_intfloat(void);
void extract_float(INTFLOAT_PTR x, float f);
void print_intfloat(INTFLOAT_PTR x, float f);
void part2();

#endif
