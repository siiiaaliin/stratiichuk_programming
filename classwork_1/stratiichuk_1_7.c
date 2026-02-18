#include <stdio.h>
#include <math.h>

int main(){
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    int x1=(int)x;
    printf("Integer part: %d\n", x1);

    double x2=x-x1;
    printf("Fractional part: %.6f\n", x2);

    int x3=(int)round(x);
    printf("Rounded fractional part: %d\n", x3);

    int x4=(int)ceil(x);
    printf("Ceiling value: %d\n", x4);

    int x5=(int)floor(x);
    printf("Floor value: %d\n", x5);

    return 0;
}