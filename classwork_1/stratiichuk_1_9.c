#include <stdio.h>

int main(){
    double a, b;
    printf("Enter a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Arithmetic mean: %.e\n", (a+b)/2);
    printf("Arithmetic mean: %.6f\n", (a+b)/2);
    printf("Harmonic mean: %.e\n", 2/((1/a)+(1/b)));
    printf("Harmonic mean: %.6f\n", 2/((1/a)+(1/b)));
}    