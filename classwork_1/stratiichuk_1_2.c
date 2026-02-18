#include <stdio.h>
#include <math.h>

int main()
{
    float x=0.0001f;
    double x1=0.0001;
    double x2=1e-04;
    printf("x=%g, x1=%g, x2=%g\n", x, x1, x2);

    double x3=24.33E5;
    printf("x3=%.2lf\n", x3);

    long double x_pi=3.14159265358979323846264338327950288419716939937510L;
    printf("x_pi=%.50Lf\n", x_pi);
    long double x_pi2=M_PI;
    printf("x_pi2=%.50Lf\n", x_pi2);

    double e1=exp(1.0);
    printf("e1=%.2lf\n", e1);

    double s1=sqrt(5);
    printf("s1=%.2lf\n", s1);

    double s2=log(100);
    printf("log(100)=%.2lf\n", s2);
}