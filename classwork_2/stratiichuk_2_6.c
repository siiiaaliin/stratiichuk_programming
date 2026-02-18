#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b){
    return sqrt(a*a+b*b);
}

double area_heron(double a, double b, double c){
    double s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    double x1, y1, x2, y2, x3, y3;
    printf("point A: ");
    scanf("%lf %lf", &x1, &y1);
    printf("point B: ");
    scanf("%lf %lf", &x2, &y2);
    printf("point C: ");
    scanf("%lf %lf", &x3, &y3);

    double a=hypotenuse(x2-x1, y2-y1);
    double b=hypotenuse(x3-x2, y3-y2);
    double c=hypotenuse(x1-x3, y1-y3);

    printf("Area of triangle by Heron's formula: %.6f\n", area_heron(a, b, c));
}
