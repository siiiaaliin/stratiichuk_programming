#include <stdio.h>

int main(){
    double x, y;
    printf("\nx=");
    scanf("%lf", &x);

// a)
    x=x*x;
    y=x*x; //x^4
    printf("x^4=%lf\n", y);

// б)
    x=x*x;
    y=x*x*x; //x^6
    printf("x^6=%lf\n", y);

// в)
    x=x*x*x;
    y=x*x*x; //x^9
    printf("x^9=%lf\n", y);

// г)
    y=x*x;
    y=y*y;
    y=y*y;
    y=y*y;
    y=y/x; //x^15
    printf("x^15=%lf\n", y);
    
// д)
    y=x*x;
    y=y*y;
    y=y*y;
    y=y/x;
    y=y*y;
    y=y*y; //x^28
    printf("x^28=%lf\n", y);

// е)
    y=x*x;
    y=y*y;
    y=y*y;
    y=y*y;
    y=y*y;
    y=y*y; //x^64
    printf("x^64=%lf\n", y);

}