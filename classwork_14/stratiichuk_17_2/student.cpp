#include <iostream>
#include <string>
#include <cctype>

#include "student.h"

void Student::show(){
    std::cout<<pib<<" ,"<<age<<" ,"<<(gender?"male":"female")<<"\n";
    std::cout<<kurs<<" ,"<<grupa<<" ,"<<VUZ<<"\n";
}

int Student::input(){
    Humanoid::input();
    std::cout<<"Input kurs, grupa and VUZ: ";
    try{
        std::cin>>kurs;
        std::cin>>grupa;
        std::cin>>VUZ;
    }
    catch(...){
        throw std::exception();
    }
    return 0;
}