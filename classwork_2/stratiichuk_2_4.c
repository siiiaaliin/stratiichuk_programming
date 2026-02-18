#include <stdio.h>

// // а)
// double func1(double x){
//     double y=x*x+1;
//     return y*y;
// }

// г)
double func(double x){
    double y=x*x*x;
    double z=y*y*y;
    return z+y+1;
}

int main(){
    double x, y;
    printf("Enter x: ");
    scanf("%lf", &x);
    // y=func1(x);
    y=func(x);
    printf("Result: y=%.6f\n", y);
}

