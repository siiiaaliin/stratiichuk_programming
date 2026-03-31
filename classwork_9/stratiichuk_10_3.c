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

struct Date tomorrow(struct Date d){
    int days_in_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(d.year%4==0 && ((d.year%100!=0) || d.year%400==0)){
        days_in_month[1]=29;
    }
    d.day++;
    if(d.day>days_in_month[d.month-1]){
        d.day=1;
        d.month++;
        if(d.month>12){
            d.month=1;
            d.year++;
        }
    }
    return d;
}

int day_of_week(struct Date d){
    int a=(14-d.month)/12;
    int y=d.year-a;
    int m=d.month+12*a-2;
    int j=(d.day+y+y/4-y/100+y/400+(31*m)/12)%7;
    return j;
}

int main(){
    struct Date d;
    input_Date(&d);
    printf("Today: ");
    print_Date(d);
    printf("\nTomorrow: ");
    print_Date(tomorrow(d));
    if (day_of_week(tomorrow(d))==0) printf("\nSunday");
    else if (day_of_week(tomorrow(d))==1) printf("\nMonday");
    else if (day_of_week(tomorrow(d))==2) printf("\nTuesday");
    else if (day_of_week(tomorrow(d))==3) printf("\nWednesday");
    else if (day_of_week(tomorrow(d))==4) printf("\nThursday");
    else if (day_of_week(tomorrow(d))==5) printf("\nFriday");
    else printf("\nSaturday");
}