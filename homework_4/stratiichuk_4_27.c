#include <stdio.h>
#include <math.h>

//е)
int main(){
    double eps;
    printf("Enter epsilon: ");
    scanf("%lf", &eps);

    double term=1.0;
    double sum=0.0;
    double power=1.0;
    int sign=1;
    int i=0;
    while(fabs(term)>=eps){
        term=sign/(power*(2*i+1));
        sum+=term;
        power*=3;
        sign*=-1;
        i++;
    }

    double pi=2*sqrt(3)*sum;
    printf("Result: %lf\n", pi);
}