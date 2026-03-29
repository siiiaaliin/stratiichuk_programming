#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mountain{
    char name[100];
    double height;
};

struct Mountain input_Mountain(){
    struct Mountain m;
    printf("Input mountain name: ");
    scanf("%s", m.name);
    printf("Input mountain height: ");
    scanf("%lf", &m.height);
    return m;
}

void print_Mountain(struct Mountain m){
    printf("%s: %lf\n", m.name, m.height);
}

int find_highest(struct Mountain* mountains, int n){
    int max=0;
    for(int i=1; i<n; i++){
        if(mountains[i].height>mountains[max].height){
            max=i;
        }
    }
    return max;
}

int find_height(struct Mountain* mountains, int n, char* name){
    for(int i=0; i<n; i++){
        if(strcmp(mountains[i].name, name)==0){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Input number of mountains: ");
    scanf("%d", &n);

    struct Mountain* mountains=(struct Mountain*)calloc(n, sizeof(struct Mountain));
    for(int i=0; i<n; i++){
        mountains[i]=input_Mountain();
    }

    int h=find_highest(mountains, n);
    printf("Highest mountain: ");
    print_Mountain(mountains[h]);

    char name[100];
    printf("Input mountain name to find: ");
    scanf("%s", name);

    int idx=find_height(mountains, n, name);
    if(idx!=-1){
        printf("Mountain found: ");
        print_Mountain(mountains[idx]);
    }
    else{
        printf("Mountain not found\n");
    }

    free(mountains);
}