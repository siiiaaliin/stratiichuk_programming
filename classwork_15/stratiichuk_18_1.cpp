#include <iostream>
#include "Rat.h"

namespace maximum{
    template <typename T>
    T max(T a, T b){
        return (a>b) ?a:b;
    }

    template <>
    std::string max<std::string>(std::string a, std::string b){
        return (a>b) ?a:b;
    }

    template <>
    const char* max<const char*>(const char* a, const char* b){
        return (strcmp(a,b)>0) ?a:b;
    }
}

int main(){
    std::string str1="abc";
    std::string str2="def";
    std::cout<<maximum::max(str2, str1)<<std::endl;
    std::cout<<maximum::max("gbc", "def")<<std::endl;

    Rational r1=Rational(1,2);
    Rational r2=Rational(2,3);
    std::cout<<maximum::max(r1,r2)<<std::endl;
    return 0;
}