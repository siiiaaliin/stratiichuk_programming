#include <stdio.h>

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double a[n+1];
    double sum=0;
    for(int i=1; i<=n; i++){
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
        sum+=a[i];
    }

    double max=a[1];
    double min=a[1];
    for(int i=2; i<=n; i++){
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }
    }

    double result=(sum-max-min)/(n-2);
    printf("result=%lf\n", result);
}