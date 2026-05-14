#include <iostream>
#include <string>
#include <cctype>

#include "lecturer.h"

void Lecturer::show(){
    std::cout<<pib<<" ,"<<age<<" ,"<<(gender?"male":"female")<<"\n";
    std::cout<<posada<<" ,"<<VUZ1<<"\n";
}

int Lecturer::input(){
    Humanoid::input();
    std::cout<<"VUZ, posada, z/p: ";
    std::cin>>VUZ1;
    std::cin>>posada;
    std::cin>>salary;
    return 0;
}