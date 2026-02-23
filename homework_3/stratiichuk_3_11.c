#include <stdio.h>
#include <math.h>

void func1(){
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    if(x>=0){
        printf("|%lf|=%lf\n", x, x);
    }
    else{
        printf("|%lf|=%lf\n", x, -x);
    }
}

void func2(){
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    if(x>=0){
        if(x-1>=0){
            printf("||%lf|-1|-1=%lf\n", x, x-2);
        }
        else{
            printf("||%lf|-1|-1=%lf\n", x, -x);
        }
    }
    else{
        if(-x-1>=0){
            printf("||%lf|-1|-1=%lf\n", x, -x-2);
        }
        else{
            printf("||%lf|-1|-1=%lf\n", x, x);
        }
    }
}

void func3(){
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    if(x>0){
        printf("sign(%lf)=1\n", x);
    }
    else if(x<0){
        printf("sign(%lf)=-1\n", x);
    }
    else{
        printf("sign(%lf)=0\n", x);
    }
}

void func4(){
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    if(x>=0){
        printf("sin(|%lf|)=%lf\n", x, sin(x));
    }
    else{
        printf("sin(|%lf|)=%lf\n", x, sin(-x));
    }
}

int main(){
    func1();
    func2();
    func3();
    func4();
}