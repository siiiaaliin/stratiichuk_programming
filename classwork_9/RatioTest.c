#include "Ratio.h"
#include <stdio.h>

int main(){
    Rational x;
    Rational y;
    printf("Enter x: ");
    input_Rational(&x);
    printf("x=");
    print_Rational(x);
    printf("\n");

    printf("Enter y: ");
    input_Rational(&y);
    printf("y=");
    print_Rational(y);

    printf("\nsum=");
    print_Rational(add(x, y));

    printf("\nmul=");
    print_Rational(mul(x, y));
}
