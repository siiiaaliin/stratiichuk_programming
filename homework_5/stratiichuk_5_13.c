#include <stdio.h>
#include <math.h>

//б)
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double a1=1;
    double b1=1;
    double p=a1*b1;
    double a, b;
    for(int i=2; i<=n; i++){
        a=(sqrt(b1)+a1)/5;
        b=2*b1+5*a1*a1;
        p*=a*b;
        a1=a;
        b1=b; 
    }

    printf("p=%.6lf\n", p);
}