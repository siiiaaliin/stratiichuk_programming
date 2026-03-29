#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

size_t input(double* r, size_t n){
    for (size_t i=0; i<n; i++){
        printf("r[%zu]=", i);
        int a=scanf("%lf", &r[i]);
        if (a!=1) return i;
    }
    return n;
}

double sum_sqr(double* r, size_t n){
    double s=0;
    for (size_t i=0; i<n; i++){
        s+=r[i]*r[i];
    }
    return s;
}

void task_1(){
    size_t n;
    printf("n=");
    scanf("%zu", &n);
    double* r=(double*)malloc(n*sizeof(double));
    size_t k=input(r, n);
    double s=sum_sqr(r, k);
    printf("sum=%lf\n", s);
    free(r);
}



bool is_sqr(int n){
    int m=floor(sqrt(n));
    return m*m==n;
}

bool is_cube(int n){
    int m=floor(pow(n, 1.0/3));
    return m*m*m==n;
}

size_t input_int(int* r, size_t n){
    for (size_t i=0; i<n; i++){
        printf("r[%zu]=", i);
        scanf("%d", &r[i]);
        if (r[i]==0) return i;
    }
    return n;
}

void task_2(){
    int n;
    printf("n=");
    scanf("%d", &n);
    int* r=(int*)malloc(n*sizeof(int));
    size_t k=input_int(r, n);
    int y=0, w=0;
    for (int i=0; i<k; i++){
        if (is_sqr(r[i])){
            y++;
        }
        if (is_cube(r[i])){
            w++;
        }
    }
    printf("%d %d", y, w);
    free(r);
}



double* input_h(int n){
    double* h=(double*)calloc(n, sizeof(double));
    for (int i=0; i<n; i++){
        scanf("%lf", &h[i]);
    }
    return h;
}

int diff(double* v1, double* v2, double* v3, int n){
    for (int i=0; i<n; i++){
        v3[i]=v1[i]-v2[i];
    }
    return 0;
}

void task_3(){
    int n;
    printf("n=");
    scanf("%d", &n);
    double* v1=input_h(n);
    double* v2=input_h(n);
    double* v3=calloc(n, sizeof* v3);
    diff(v1, v2, v3, n);
    for (int i=0; i<n; i++){
        printf("%lf, ", v3[i]);
    }
    free(v1);
    free(v2);
    free(v3);
}



double** input_matrix_2d(int n){
    double** a=(double**)calloc(n, sizeof(double*));
    for (int i=0; i<n; i++){
        a[i]=(double*)calloc(n, sizeof(double));
        for (int j=0; j<n; j++){
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    return a;
}

void free_matrix_2d(double** a, int n){
    for (int i=0; i<n; i++){
        free(a[i]);
    }
    free(a);
}

double** mult_matrix_2d(double** a, double** b, int n){
    double** c=(double**)calloc(n, sizeof(double*));
    for (int i=0; i<n; i++){
        c[i]=(double*)calloc(n, sizeof(double));
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

void print_matrix_2d(double** c, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }
}

void task_4a(){
    int n;
    printf("n=");
    scanf("%d", &n);
    double** a=input_matrix_2d(n);
    double** b=input_matrix_2d(n);
    double** c=mult_matrix_2d(a, b, n);
    print_matrix_2d(c, n);
    free_matrix_2d(a, n);
    free_matrix_2d(b, n);
    free_matrix_2d(c, n);
}



double* input_matrix_1d(int n){
    double* a=(double*)calloc(n*n, sizeof(double));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i*n+j]);
        }
    }
    return a;
}

double* mult_matrix_1d(double* a, double* b, int n){
    double* c=(double*)calloc(n*n, sizeof(double));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                c[i*n+j]+=a[i*n+k]*b[k*n+j];
            }
        }
    }
    return c;
}

void print_matrix_1d(double* c, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%lf ", c[i*n+j]);
        }
        printf("\n");
    }
}

void task_4b(){
    int n;
    printf("n=");
    scanf("%d", &n);
    double* a=input_matrix_1d(n);
    double* b=input_matrix_1d(n);
    double* c=mult_matrix_1d(a, b, n);
    print_matrix_1d(c, n);

    free(a);
    free(b);
    free(c);
}

int main(){
    // task_1();
    // task_2();
    // task_3();
    // task_4a();
    task_4b();
    return 0;
}