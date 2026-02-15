#include <stdio.h>
#include <math.h>

int main(){
    double x;
    printf("введіть дійсне число від 0 до 10000: ");
    scanf("%lf", &x);
    printf("%20.4lf\n", pow(x, 8));
}