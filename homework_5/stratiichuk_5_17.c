#include <stdio.h>

//a)
int main(){
    double x, eps;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter epsilon: ");
    scanf("%lf", &eps);

    double term=1, sum=1;
    int i=1;
    while(term>=eps){
        term*=x*x/((2*i-1)*(2*i));
        sum+=term;
        i++;
    }

    printf("Result: %lf\n", sum);
    printf("Count terms: %d\n", i);
}