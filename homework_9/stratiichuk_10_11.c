#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resident{
    char surname[100];
    char city[100];
    char street[100];
    int house;
    int flat;
};

struct Resident input_Resident(){
    struct Resident r;
    printf("Input surname: ");
    scanf("%s", r.surname);
    printf("Input city: ");
    scanf("%s", r.city);
    printf("Input street: ");
    scanf("%s", r.street);
    printf("Input house: ");
    scanf("%d", &r.house);
    printf("Input flat: ");
    scanf("%d", &r.flat);
    return r;
}

void print_Resident(struct Resident r){
    printf("%s, %s, %s, %d, %d\n", r.surname, r.city, r.street, r.house, r.flat);
}

void find_same_addresses(struct Resident* p, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(p[i].city, p[j].city)!=0 && strcmp(p[i].street, p[j].street)==0 && p[i].house==p[j].house && p[i].flat==p[j].flat){
                printf("Found:\n");
                print_Resident(p[i]);
                print_Resident(p[j]);
                return;
            }
        }
    }
    printf("Not found\n");
}

int main(){
    int n;
    printf("n=");
    scanf("%d", &n);

    struct Resident* p=(struct Resident*)calloc(n, sizeof(struct Resident));
    for(int i=0; i<n; i++){
        p[i]=input_Resident();
    }

    find_same_addresses(p, n);

    free(p);
    return 0;
}
