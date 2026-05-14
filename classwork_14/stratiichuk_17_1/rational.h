#ifndef __RATIONAL_H__
#define __RATIONAL_H__

#include <iostream>
#include <exception>
#include <string>


class Rational_exception : public std::exception{
public:
    const char* what() const noexcept override{
        return "Denominator cannot be zero";
    }
};

class Rational{
    int numerator;
    int denominator;
public:
    Rational(int numerator=0, int denominator=1);
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator-() const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);

    void setNumerator(int numerator);
    void setDenominator(int denominator);
    int getNumerator() const;
    int getDenominator() const;

    void reduce();

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator>=(const Rational& other) const;

    friend void writeRationalToFile(const Rational& r, const std::string& filename);
    friend Rational readRationalFromFile(const std::string& filename);
};

void writeRationalToFile(const Rational& r, const std::string& filename);
Rational readRationalFromFile(const std::string& filename);

#endif // __RATIONAL_H__