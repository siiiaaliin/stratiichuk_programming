#include <stdio.h>
#include <stdlib.h>

double* input_vector(int n){
    double* v=(double*)calloc(n, sizeof(double));
    for (int i=0; i<n; i++){
        printf("v[%d]=", i);
        scanf("%lf", &v[i]);
    }
    return v;
}

double arithmetic_mean(double* v, int n){
    double s=0;
    for (int i=0; i<n; i++){
        s+=v[i];
    }
    return s/n;
}

double dispersion(double* v, int n){
    double m=arithmetic_mean(v, n);
    double s=0;
    for (int i=0; i<n; i++){
        s+=(v[i]-m)*(v[i]-m);
    }
    return s/n;
}

int main(){
    double* all=(double*)calloc(1000, sizeof(double));
    int total=0;
    while (1){
        int n;
        printf("n=");
        scanf("%d", &n);
        if (n==0){
            break;
        }

        double* v=input_vector(n);
        for (int i=0; i<n; i++){
            all[total+i]=v[i];
        }
        total+=n;
        free(v);

        printf("arithmetic mean=%lf\n", arithmetic_mean(all, total));
        printf("dispersion=%lf\n", dispersion(all, total));
    }
    free(all);
}