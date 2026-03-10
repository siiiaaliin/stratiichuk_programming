#include <stdio.h>
// #define N 3 //task 1, 2
// #define N 20 //task 3
// #define N 25 //task 4, 5
#define N 100 //task 6, 7

void print_matrix(int matrix[N][N], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void task1(){
    int matrix[N][N]={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(matrix[i][j]==m){
                matrix[i][j]=n;
            }
        }
    }
    print_matrix(matrix, N, N);
}



void print_matrix_double(double matrix[N][N], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void task2(){
    double matrix[N][N]={{1.0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j;
    printf("Enter i and j: ");
    scanf("%d %d", &i, &j);
    double a;
    printf("Enter a: ");
    scanf("%lf", &a);

    if(i>=0 && i<N && j>=0 && j<N){
        matrix[i][j]=a;
    }
    else{
        printf("Incorrect index\n");
    }

    print_matrix_double(matrix, N, N);
}



int input_matrix(double matr[N][N], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("a[%d][%d]=", i, j);
            int r=scanf("%lf", &matr[i][j]);
            if(r!=1) return -1;
        }
    }
    return 0;
}

void task3(){
    double matrix[N][N];
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);
    input_matrix(matrix, n, m);
    print_matrix_double(matrix, n, m);
}



void input_matrix_row(double matr[N][N], int n, int m){
    for(int i=0; i<n; i++){
        printf("Row %d: ", i);
        for(int j=0; j<m; j++){
            scanf("%lf", &matr[i][j]);
        }
    }
}

void task4(){
    double matrix[N][N];
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);
    input_matrix_row(matrix, n, m);
    print_matrix_double(matrix, n, m);
}



void transpose(double matr[N][N], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            double c=matr[i][j];
            matr[i][j]=matr[j][i];
            matr[j][i]=c;
        }
    }    
}

void task5(){
    double a[N][N];
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    input_matrix(a, n, n);
    transpose(a, n);
    print_matrix_double(a, n, n);
}



void transpose_2(double matr[N][N], double matrout[N][N], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrout[j][i]=matr[i][j];
        }
    }
}

void task5_v2(){
    double martr[N][N];
    double martrout[N][N];
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    input_matrix(martr, n, n);
    transpose_2(martr, martrout, n);
    print_matrix_double(martrout, n, n);
}



void sum(double matr[N][N], int n, int m, int k){
    double sum=0;
    int found=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i-j==k){
                sum+=matr[i][j];
                found=1;
            }
        }
    }
    if(found==0){
        printf("sum=0\n");
    }
    else{
        printf("sum=%lf\n", sum);
    }  
}

void task6(){
    double matrix[N][N];
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);
    input_matrix(matrix, n, m);
    print_matrix_double(matrix, n, m);
    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    sum(matrix, n, m, k);
}



void determinant(double matr[N][N], int n){
    double det=1;
    for(int k=0; k<n; k++){
        for(int i=k+1; i<n; i++){
            double c=matr[i][k]/matr[k][k];
            for(int j=k; j<n;j++){
                matr[i][j]=matr[i][j]-c*matr[k][j];
            }
        }
    }
    for(int i=0; i<n; i++){
        det*=matr[i][i];
    }

    printf("det=%lf\n", det);
}


void task7(){
    double matrix[N][N];
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    input_matrix(matrix, n, n);
    print_matrix_double(matrix, n, n);
    determinant(matrix, n);
}

int main(){
    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
    // task5_v2();
    // task6();
    task7();
    return 0;
}
