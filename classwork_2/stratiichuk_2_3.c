#include <stdio.h>
#include <math.h>

double area_heron(double a, double b, double c){
    double s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    double a, b, c;
    printf("Enter a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double area=area_heron(a, b, c);
    printf("Area: %.6f\n", area);
}