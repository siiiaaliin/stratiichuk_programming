#include <stdio.h>
#include <math.h>

double cylinder_volume(double r, double h){
    return M_PI*r*r*h;
}

int main(){
    double r, h;
    printf("r, h: ");
    scanf("%lf %lf", &r, &h);
    printf("V=%lf\n", cylinder_volume(r, h));
}
