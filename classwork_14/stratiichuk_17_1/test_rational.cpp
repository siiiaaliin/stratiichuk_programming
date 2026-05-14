#include "rational.h"
#include <iostream>

int main() {
    Rational r1(1, 2);
    Rational r2(3, 4);

    std::cout << "R1: "<<r1<<std::endl;
    std::cout << "R2: "<<r2<<std::endl;

    Rational sum=r1+r2;
    Rational difference=r1-r2;
    Rational product=r1*r2;
    Rational quotient=r1/r2;
    Rational negation=-r1;

    std::cout<<"R1+R2: "<<sum<<std::endl;
    std::cout<<"R1-R2: "<<difference<<std::endl;
    std::cout<<"R1*R2: "<<product<<std::endl;
    std::cout<<"R1/R2: "<<quotient<<std::endl;
    std::cout<<"-R1: "<<negation<<std::endl;

    Rational r;
    try{
        std::cout<<"Enter a rational number (numerator/denominator): ";
        std::cin>>r;
    }catch(const Rational_exception& e){
        std::cout<<"Caught exception: "<<e.what()<<std::endl;
        r.setNumerator(0);
        r.setDenominator(1);
    }

    std::cout<<"You entered: "<<r<<std::endl;

    return 0;
}