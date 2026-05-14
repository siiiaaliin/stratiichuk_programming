#include <iostream>
#include "Rat.h"

void Rational::input(){
    std::cout<<"input num, den:";
    std::cin>>num>>den;
}

void Rational::output(){
    std::cout<<num<<"/"<<den<<"\n";
}

Rational Rational::add(Rational z){
    Rational n;
    n.num=num*z.den+z.num*den;
    n.den=den*z.den;
    n.reduce();
    return n;
}

unsigned Rational::gcd(unsigned a, unsigned b){
    unsigned c;
    while(a!=0){
        c=a;
        a=b%a;
        b=c;
    }
    return b;
}

void Rational::reduce(){
    unsigned a=gcd(num, den);
    num=num/a;
    den=den/a;
}

Rational Rational::mul(Rational z){
    Rational n;
    n.num=num*z.num;
    n.den=den*z.den;
    n.reduce();
    return n;
}

bool Rational::less(Rational z){
    return num*z.den<z.num*den;
}