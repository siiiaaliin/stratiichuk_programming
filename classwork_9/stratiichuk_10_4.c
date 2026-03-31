#include <stdio.h>

typedef struct {
int numerator;
unsigned int denominator;
} Rational;

void print_Rational(Rational r){
    printf("%d/%u", r.numerator, r.denominator);
}

Rational input_Rational(){
    Rational r;
    printf("Input rational number (numerator/denominator): ");
    scanf("%d/%u", &r.numerator, &r.denominator);
    return r;
}

int gcd(int a, int b){
    while (b){
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

Rational reduce(Rational r){
    int g=gcd(r.numerator, r.denominator);
    r.numerator/=g;
    r.denominator/=g;
    return r;
}

Rational sum(Rational r1, Rational r2){
    Rational r;
    r.numerator=r1.numerator*r2.denominator+r2.numerator*r1.denominator;
    r.denominator=r1.denominator*r2.denominator;
    return reduce(r);
}

int main(){
    Rational r1=input_Rational();
    Rational r2=input_Rational();
    printf("Sum: ");
    print_Rational(sum(r1, r2));
}