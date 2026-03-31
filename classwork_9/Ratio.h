#ifndef __RATIO_H__
#define __RATIO_H__

typedef struct {
    int numerator;
    unsigned int denominator;
} Rational;

void print_Rational(Rational r);

int input_Rational(Rational *r);

Rational add(Rational x, Rational y);

Rational mul(Rational x, Rational y);

void reduce(Rational *r);

#endif // __RATIO_H__