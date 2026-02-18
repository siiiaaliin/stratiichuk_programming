#include <stdio.h>

double rosenbrock2d(double x, double y){
    return 100*(x*x-y)*(x*x-y)+(x-1)*(x-1);
}

int main(){
    printf("Rosenbrock 2D function:\n");
    printf("f(1, 1)=%.6f\n", rosenbrock2d(1, 1));
    printf("f(0, 0)=%.6f\n", rosenbrock2d(0, 0));
    printf("f(-1, 1)=%.6f\n", rosenbrock2d(-1, 1));
    printf("f(2, 2)=%.6f\n", rosenbrock2d(2, 2));
}
