#include <iostream>
#include <string>
#include <cctype>

#include "human.h"

Humanoid::Humanoid(std::string name, unsigned age_, std::string sex):
pib(name){
    age=age_;
    if(sex=="male"){
        gender=false;
    }
    else if(sex=="female"){
        gender=true;
    }
    else{
        throw "Incorrect gender";
    }
}

void Humanoid::show(){
    std::cout<<pib<<" ,"<<age<<" ,"<<(gender?"male":"female")<<"\n";
}

int Humanoid::input(){
    std::cout<<"Input name, age and gender: ";  
    std::cin>>pib;
    std::cin>>age;
    std::string sex;
    std::cin>>sex;
    if(sex.length()>0){
        char c=std::tolower(sex[0]);
        if(c=='m'){
            gender=false;
        }
        else if(c=='f' || c=='w'){
            gender=true;
        }
        else{
            throw "Incorrect gender";
        }
    }
    return 0;
}