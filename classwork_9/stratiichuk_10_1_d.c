#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Polinome{
    size_t n;
    double* x;
};

void print_Polinome(struct Polinome* y){
    printf("%lf", y->x[0]);
    for(size_t i=1; i<=y->n; i++){
    printf("+%lf*x^%zu", y->x[i], i);
    }
}

int input_Polinome(struct Polinome* y){
    printf("n=");
    scanf("%zu", &y->n);
    y->x=(double*)malloc((y->n+1)*sizeof(double));
    for(size_t i=0; i<=y->n; i++){
        printf("a[%zu]=", i);
        scanf("%lf", &y->x[i]);
    }
    return true;
}

void delete_Polinome(struct Polinome* y){
    if(y&&y->x){
        free(y->x);
    }                   
}

int main(){
    struct Polinome a;
    input_Polinome(&a);
    print_Polinome(&a);
    delete_Polinome(&a);
}