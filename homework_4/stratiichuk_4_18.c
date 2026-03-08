#include <stdio.h>

//б)
int main(){
    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    double power=1.0;
    double factorial=1.0;
    for(int i=1; i<=k; i++){
        power*=x*x;
        factorial*=(2*i-1)*(2*i);
    }

    double result=power/factorial;
    printf("Result: %lf\n", result);
}
