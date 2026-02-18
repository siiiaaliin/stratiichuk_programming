#include <stdio.h>
#include <math.h>

double cosh_calculate(double x){
    return (exp(x)+exp(-x))/2.0;
}

int main(){
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);
    double cosh_x1=cosh(x);
    double cosh_x2=cosh_calculate(x);
    printf("cosh(x): %.6f\n", cosh_x1);
    printf("cosh(x) calculated manually: %.6f\n", cosh_x2);
}