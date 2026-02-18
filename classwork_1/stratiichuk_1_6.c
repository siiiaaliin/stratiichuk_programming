#include <stdio.h>

int main(){
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit=9*celsius/5+32;
    printf("Temperature in Fahrenheit: %g", fahrenheit);
}

// int main(){
//     double celsius, fahrenheit;
//     printf("Enter temperature in Fahrenheit: ");
//     scanf("%lf", &fahrenheit);
//     celsius=(fahrenheit-32)*5/9;
//     printf("Temperature in Celsius: %g", celsius);
// }
