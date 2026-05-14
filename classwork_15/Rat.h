#ifndef __RAT_H_
#define __RAT_H_
#include <iostream>
#include <fstream>

using namespace std;

class Rational{
    int num;
    unsigned den;

    private:
    unsigned gcd(unsigned a, unsigned b);
    void reduce();


    public:
    Rational(int x, unsigned y){
        num=x;
        den=y;
        reduce();
    }
    Rational(){}
    void input();
    void output();
    Rational add(Rational z);
    Rational mul(Rational z);
    bool less(Rational z);
    void save(const char* f){
        ofstream g(f);
        if(g.bad()){
            cout<<"cannot open file"<<f;
            return;
        }
        g<<num<<"/"<<den<<"\n";
        g.close();
    }

    friend istream& operator>>(istream& in, Rational& r){
        cout<<"input num, den:";
        in>>r.num>>r.den;
        r.reduce();
        return in;
    }

    friend ostream& operator<<(ostream& out, Rational r){
        out<<r.num<<"/"<<r.den<<"\n";
        return out;
    }

    Rational operator+(Rational z){
        return add(z);
    }

    bool operator<(Rational z){
        return less(z);
    }

    bool operator>(Rational z){
        return z.less(*this);
    }
};

#endif