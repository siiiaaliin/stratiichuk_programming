#include <stdio.h>
#include "Ratio.h"

void print_Rational(Rational r){
    printf("%d/%u", r.numerator, r.denominator);
}

int input_Rational(Rational *r){
    return scanf("%d/%u", &r->numerator, &r->denominator)==2;
}

Rational add(Rational x, Rational y){
    Rational z;
    z.numerator=x.numerator*y.denominator+y.numerator*x.denominator;
    z.denominator=x.denominator*y.denominator;
    reduce(&z);
    return z;
}

Rational mul(Rational x, Rational y){
    Rational z;
    z.numerator=x.numerator*y.numerator;
    z.denominator=x.denominator*y.denominator;
    reduce(&z);
    return z;
}

int nsd(int x, int y){
    if(x>y){
        int t=x;
        x=y;
        y=t;
    }
    if(x==0){
        return y;
    }
    return nsd(y%x, x);
}

void reduce(Rational *r){
    int a=nsd(r->numerator, r->denominator);
    r->numerator/=a;
    r->denominator/=a;
}

