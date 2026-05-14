#include "rational.h"
#include <numeric>
#include <fstream>
#include <stdexcept>

Rational::Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator){
    if (denominator==0){
        throw Rational_exception();
    }
    reduce();
}

void Rational::setNumerator(int numerator){
    this->numerator=numerator;
    reduce();
}

void Rational::setDenominator(int denominator){
    if (denominator==0){
        throw Rational_exception();
    }
    this->denominator=denominator;
    reduce();
}

int Rational::getNumerator() const{
    return numerator;
}

int Rational::getDenominator() const{
    return denominator;
}

void Rational::reduce(){
    int gcd=std::gcd(numerator, denominator);
    numerator/=gcd;
    denominator/=gcd;
}

Rational Rational::operator+(const Rational& other) const{
    int newNumerator=numerator*other.denominator+other.numerator*denominator;
    int newDenominator=denominator*other.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator-(const Rational& other) const{
    int newNumerator=numerator*other.denominator-other.numerator*denominator;
    int newDenominator=denominator*other.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator-() const{
    return Rational(-numerator, denominator);
}

Rational Rational::operator*(const Rational& other) const{
    int newNumerator=numerator*other.numerator;
    int newDenominator=denominator*other.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator/(const Rational& other) const{
    if (other.numerator==0){
        throw Rational_exception();
    }
    int newNumerator=numerator*other.denominator;
    int newDenominator=denominator*other.numerator;
    return Rational(newNumerator, newDenominator);
}

std::ostream& operator<<(std::ostream& os, const Rational& r){
    os<<r.numerator<<"/"<<r.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r){
    char slash;
    is>>r.numerator>>slash>>r.denominator;
    if (r.denominator==0){
        throw Rational_exception();
    }
    r.reduce();
    return is;
}

void writeRationalToFile(const Rational& r, const std::string& filename){
    std::ofstream outFile(filename);
    if (!outFile){
        throw std::runtime_error("Could not open file for writing");
    }
    outFile<<r.numerator<<"/"<<r.denominator;
    outFile.close();
} 

Rational readRationalFromFile(const std::string& filename){
    std::ifstream inFile(filename);
    if (!inFile){
        throw std::runtime_error("Could not open file for reading");
    }
    Rational r;
    char slash;
    inFile>>r.numerator>>slash>>r.denominator;
    if (r.denominator==0){
        throw Rational_exception();
    }
    r.reduce();
    inFile.close();
    return r;
}