#include <stdio.h>

//в)
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double a[n+1];
    for(int i=1; i<=n; i++){
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
    }

    double max=a[2];
    for(int i=2; i<=n; i+=2){
        if(a[i]>max){
            max=a[i];
        }
    }
    printf("max(a2, a4, ...)=%lf\n", max);
}