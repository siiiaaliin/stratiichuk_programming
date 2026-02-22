#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();
void task11();
void task12();

int main(){
    int task_num;
    printf("Enter task number: ");
    scanf("%d", &task_num);
    if(task_num==1){
        printf("Task 1:\n");
        task1();
    } else if(task_num==2){
        printf("Task 2:\n");
        task2();
    } else if(task_num==3){
        printf("Task 3:\n");
        task3();
    } else if(task_num==4){
         printf("Task 4:\n");
        task4();
    } else if(task_num==5){
        printf("Task 5:\n");
        task5();
    } else if(task_num==6){
        printf("Task 6:\n");
        task6();
    } else if(task_num==7){
        printf("Task 7:\n");
        task7();
    } else if(task_num==8){
        printf("Task 8:\n");
        task8();
    } else if(task_num==9){
        printf("Task 9:\n");
        task9();
    } else if(task_num==10){
        printf("Task 10:\n");
        task10();
    } else if(task_num==11){
        printf("Task 11:\n");
        task11();
    } else if(task_num==12){
        printf("Task 12:\n");
        task12();
    } else {
        printf(" Invalid task number.\n");
    } 
}

void task1(){
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    double x,y;
    printf("Enter a real number: ");
    scanf("%lf", &x);

    y=x;
    for(unsigned i=0; i<n; i++){
        y=sin(y);
        printf("y_%d = %lf\n", i+1, y);
    }
    printf("Result: %lf\n", y);
}

void task2(){
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);

    printf("%u!=", n);
    for(unsigned i=1; i<n; i++){
        printf("%u*", i);
    }
    printf("%u\n",n);

    printf("%u!=", n);
    for(unsigned i=n; i>1; i--){
        printf("%u*", i);
    }
    printf("%u\n",1);
}

void task3(){
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    double x,y,power,power2,sum;
    printf("Enter a real number: ");
    scanf("%lf", &x);
    power=1;
    y=1;
    for(int i=1; i<=n; i++){
        power*=x; // x^i
        y+=power; // y=y+x^i
    }
    printf("Result: %g\n", y);

    printf("Enter a real number: ");
    scanf("%lf", &x);
    printf("Enter a real number: ");
    scanf("%lf", &y);
    
    sum=1;
    power=1;
    power2=x;
    for(int i=1; i<=n; i++){
        power*=y; // y^i
        power2*=power2; // x^(2^i)
        sum+=power*power2; //y^i*x^(2^i)
    }
    printf("Result: %g\n", sum);
}

void task4(){
    unsigned n;
    printf("Enter n:");
    scanf("%u", &n);
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    double sum=0.0;
    double power=1.0;
    for(int i=1; i<=n; i++){
        power*=x;
        sum+=i*power;
    }
    printf("Result: %lf\n", sum);
}

void task5(){
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    unsigned long long double_factorial=1UL;

    if(n%2==0){
        for(unsigned i=1; i<=n/2; i++){
            double_factorial*=(2*i);
        }
    } else {
        for(unsigned i=0; i<=n/2; i++){
            double_factorial*=(2*i+1);
        }
    }
    printf("Double factorial of %u is %llu\n", n, double_factorial);

    unsigned long long double_factorial2=1UL;
    for(unsigned i=n; i>1; i-=2){
        double_factorial2*=i;
    }
    printf("Double factorial of %u is %llu\n", n, double_factorial2);
}

void task6(){
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);

    double sqrt_res1=0.0;
    for(int i=0; i<n; i++){
        sqrt_res1=sqrt(2+sqrt_res1);
    }
    printf("y1=%lf\n", sqrt_res1);

    double sqrt_res2=0.0;
    for(int i=0; i<n; i++){
        sqrt_res2=sqrt(3*(n-i)+sqrt_res2);
    }
    printf("y2=%lf\n", sqrt_res2);
}

void task7(){
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    double x, sum;
    printf("Enter a real number: ");
    scanf("%lf", &x);

    double term=1.0; //x^i/i!
    sum=1.0; //e^x approximation
    for(unsigned i=1; i<=n; i++){
        term*=x/i; //x^i/i!
        sum+=term;
    }
    printf("e^x approximation: %lf while exp(%g)=%lf\n", sum, x, exp(x));
}

void task8(){
    unsigned m;
    printf("Enter a positive integer:");
    scanf("%u", &m);
    if(m<1){
        printf("Invalid input. m must be a positive integer.\n");
        return;
    }

    int k=0;
    unsigned prod=1;
    while(prod<=m){
        prod*=4;
        k++;
    }
    printf("k=%d\n", k-1);

    prod=1;
    k=0;
    do{
        prod*=4;
        k++;
    }while(prod<=m);

    printf("k=%d\n", k-1);
}

void task9(){
    unsigned m;
    printf("Enter a positive integer:");
    scanf("%u",&m);
    if(m<1){
        printf("Invalid input. m must be a positive integer.\n");
        return;
    }
    int k=0;
    unsigned prod=1;

    while(prod<=m){
        prod*=2;
        k++;
    }
    printf("k=%d\n",k);
}

void task10(){
    float a=1.0f;
    while (1){
        a/=2.0f;
        if(1+a==1.0f) break;
    }
    printf("Machine zero: %e\n", a);
}

void task11(){
    int i=0;
    int sum=0;
    double harm_sum=0.0;
    while (1){
        int x;
        printf("a[%d]=", i);
        scanf("%d",&x);
        if(x==0)break;
        sum+=x;
        harm_sum+=1.0/x;
        i++;
        printf("You entered: %d\n",x);
    }

    printf("sum of entered numbers: %d\n",sum);
    if(i>0){
        printf("Average: %g\n",(double)sum/i);
        printf("Harmonic mean: %g\n", i/harm_sum);
    } else {
        printf("No numbers entered.\n");
    }
    //printf("Average: %g\n",(i>0)?(double)sum/i:0.0);
}

void task12(){
    unsigned n;
    printf("Enter n: ");
    scanf("%u", &n);

    if(n>=25){
        printf("n must be less than 25\n");
    }
    
    double result=0.0;
    for(unsigned i=0; i<=n; i++){
        
        double term=1.0;
        for(unsigned j=1+i; j<=n; j++){
            term*=j;
        }

        if(i%2==0){
            result+=term;
        } else {
            result-=term;
        }
    }
    printf("!%u=%lf\n", n, result);
}