#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Field{
    char vert;
    unsigned char hor;
};

void print_Field(struct Field x){
    printf("%c %hhu", x.vert, x.hor);
    
}

struct Field input_Field(){
    struct Field f;
    printf("Input chess field: ");
    scanf(" %c %hhu", &f.vert, &f.hor);
    return f;
}

bool queen_turn(struct Field f1, struct Field f2){
    if(f1.vert==f2.vert || f1.hor==f2.hor || abs(f1.vert-f2.vert)==abs(f1.hor-f2.hor)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    struct Field f1, f2;
    f1=input_Field();
    f2=input_Field();
    if(queen_turn(f1, f2)){
        printf("Queen can move");
    }
    else{
        printf("Queen cannot move");
    }
}