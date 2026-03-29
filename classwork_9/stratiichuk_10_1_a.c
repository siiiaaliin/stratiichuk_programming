#include <stdio.h>
#include <stdbool.h>

struct Date{
    int day;
    int month;
    int year;
};

void print_Date(struct Date x){
    printf("%02d.%02d.%4d", x.day, x.month, x.year);
}

int input_Date(struct Date* x){
    printf("Input date: ");
    scanf("%2d.%2d.%4d", &(*x).day, &x->month, &x->year);
    return true;
}

int main(){
    struct Date y;
    input_Date(&y);
    print_Date(y);
}