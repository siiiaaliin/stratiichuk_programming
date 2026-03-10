#include <stdio.h>
#include <math.h>

void task1(){
    int mas[5]={1,2,3,4,5};
    int i;
    int count;
    for(i=0;i<5;i++){
        printf("%d\n",mas[i]);
    }

    double x;
    printf("Enter x: ");
    scanf("%lf",&x);

    count=0;
    for(i=0;i<5;i++){
        if(mas[i]<x){
            count++;
        }
    }
    printf("Count: %d\n",count);
}
 


void task2(){
    int mas[]={5, 112, 4, 3};
    
    for(int i=3; i>=0; i--){
        printf("%d ", mas[i]);
    }
    printf("\n");
}



#define N_3 10
int input_array_double(double ar[N_3]){
    for(int i=0; i<N_3; i++){
        printf("Input ar[%d]=", i);
        int ch=scanf("%lf",&ar[i]);
        if(ch!=1) return i;
    }
    return N_3;
}

double summary(double ar[N_3]){
    double sum=0;
    for(int i=0; i<N_3; i++){
        if(ar[i]>exp(1)){
            sum+=ar[i];
        }
    }
    return sum;
}

void task3(){
    double mas[N_3];
    int k=input_array_double(mas);
    double sum=summary(mas);
    printf("sum=%lf\n", sum);
}



#define N_4 5
int input_array_int(int ar[N_4]){
    for(int i=0; i<N_4; i++){
        printf("Input ar[%d]=", i);
        int ch=scanf("%d", &ar[i]);
        if(ch!=1) return i;
    }
    return N_4;
}

int max_array(int ar[N_4], int n){
    int maximum=ar[0];
    for(int i=1; i<n; i++){
        if(ar[i]>maximum){
            maximum=ar[i];
        }
    }
    return maximum;
}
    
void task4(){
    int mas[N_4];
    int k=input_array_int(mas);
    int maximum=max_array(mas, k);

    printf("maximum=%d\n", maximum);
}



#define N_5 50
int input_array(int ar[N_5]){
    for(int i=0; i<N_5; i++){
        printf("Input ar[%d]=",i);
        int ch=scanf("%d",&ar[i]);
        if(ch!=1) return i;
        if(ar[i]==0) return i;
    }
    return N_5;
}

void count_even_odd(int x[], int n){
    int n1=0;
    int n2=0;
    for(int i=0; i<n; i++){
        if(x[i]%2==0){
            n1++;
        }
        else{
            n2++;
        }
    }
    printf("n1=%d\n", n1);
    printf("n2=%d\n", n2);
}

void task5(){
    int mas[N_5];
    int k=input_array(mas);
    count_even_odd(mas, k);
}



#define MAX_N 20
void input_vector(double x[], int n){
    for(int i=0; i<n; i++){
        printf("x[%d]=", i);
        scanf("%lf", &x[i]);
    }
}

void print_vector(double x[], int n){
    for(int i=0; i<n; i++){
        printf("%lf ", x[i]);
    }
    printf("\n");
}

void sum_vectors(double a[], double b[], double c[], int n){
    for(int i=0; i<n; i++){
        c[i]=a[i]+b[i];
    }
}

void task6(){
    int n;
    printf("Enter vector size: ");
    scanf("%d", &n);

    double a[MAX_N];
    double b[MAX_N];
    double c[MAX_N];

    printf("Input vector A:\n");
    input_vector(a, n);

    printf("Input vector B:\n");
    input_vector(b, n);

    sum_vectors(a, b, c, n);

    printf("Sum vector A and B:\n");
    print_vector(c, n);
}



int main(){
    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
    task6();
    return 0;
}
