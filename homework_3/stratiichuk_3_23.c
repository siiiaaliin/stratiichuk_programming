#include <stdio.h>
#include <math.h>

//г)
double eReLu(double a,double x){
    if(x<0){
        return a*(exp(x)-1);
    }
    else{
        return 0;
    }
}

double eReLu_derivative(double a, double x){
    if(x<0){
        return a*exp(x);
    }
    else{
        return 0;
    }
}

int main(){
    double a, x;
    printf("Enter a and x: ");
    scanf("%lf %lf", &a, &x);
    
    printf("f(x)=%.6lf\n", eReLu(a, x));
    printf("f'(x)=%.6lf\n", eReLu_derivative(a, x));
}