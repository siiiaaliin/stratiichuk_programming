//a)
#include <stdio.h>
#include <stdlib.h>

double** input_matrix(int n, int m){
    double** a=(double**)calloc(n, sizeof(double*));
    for (int i=0; i<n; i++){
        a[i]=(double*)calloc(m, sizeof(double));
        for (int j=0; j<m; j++){
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    return a;
}

void print_matrix(double** a, int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(double** a, int n){
    for (int i=0; i<n; i++){
        free(a[i]);
    }
    free(a);
}

double** add_row(double** a, int n, int m, int k){
    double** b=(double**)calloc(n+1, sizeof(double*));
    for (int i=0; i<n+1; i++){
        b[i]=(double*)calloc(m, sizeof(double));
        
        if (i<=k){
            for (int j=0; j<m; j++){
                b[i][j]=a[i][j];
            }
        }
        else if (i==k+1){
            printf("enter new row:\n");
            for (int j=0; j<m; j++){
                printf("b[%d][%d]=", i, j);
                scanf("%lf", &b[i][j]);
            }
        }
        else {
            for (int j=0; j<m; j++){
                b[i][j]=a[i-1][j];
            }
        }
    }
    return b;
}

int main(){
    int n, m, k;
    printf("n=");
    scanf("%d", &n);
    printf("m=");
    scanf("%d", &m);
    printf("k=");
    scanf("%d", &k);

    double** a=input_matrix(n, m);
    print_matrix(a, n, m);
    double** b=add_row(a, n, m, k);
    print_matrix(b, n+1, m);

    free_matrix(a, n);
    free_matrix(b, n+1);
}