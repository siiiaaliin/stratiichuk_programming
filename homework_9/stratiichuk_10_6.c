// г)
#include <stdio.h>

struct Address{
    char city[100];
    char street[100];
    int house;
    int flat;
};

struct Address input_Address(){
    struct Address a;
    printf("Input city: ");
    scanf("%s", a.city);
    printf("Input street: ");
    scanf("%s", a.street);
    printf("Input house: ");
    scanf("%d", &a.house);
    printf("Input flat: ");
    scanf("%d", &a.flat);
    return a;
}

void print_Address(struct Address a){
    printf("%s, %s, %d, %d", a.city, a.street, a.house, a.flat);
}

int main(){
    struct Address a=input_Address();
    print_Address(a);
}