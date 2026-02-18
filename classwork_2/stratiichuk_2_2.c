#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b){
    return sqrt(a*a+b*b);
}

int main(){
    double a, b;
    printf("Enter a and b: ");
    scanf("%lf %lf", &a, &b);
    double hyp=hypotenuse(a, b);
    printf("Hypotenuse: %.6f\n", hyp);
}