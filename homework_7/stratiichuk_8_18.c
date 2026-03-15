#include <stdio.h>
#define N 100

int main(){
    double matrix[N][N];
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }

    int first=-1;
    int last=-1;
    for(int i=0; i<n; i++){
        int all_negative=1;
        for(int j=0; j<m; j++){
            if(matrix[i][j]>=0){
                all_negative=0;
                break;
            }
        }
        if(all_negative){
            if(first==-1){
                first=i;
            }
            last=i;
        }
    }
    if(first!=-1 && last!=-1 && first!=last){
        for(int j=0; j<m; j++){
            double t=matrix[first][j];
            matrix[first][j]=matrix[last][j];
            matrix[last][j]=t;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}