#include <iostream>

using namespace std;

class Polynome{
    double* c;
    int n;
    
    public:
    Polynome():c(nullptr), n(0){}

    Polynome(int n){
        c=new double[n];
        this->n=n;
    }

    ~Polynome(){
        delete[] c;
    }

    Polynome(int n, double* d){
        c=new double[n];
        this->n=n;
        for(int i=0; i<n; i++){
            c[i]=d[i];
        }
    }

    Polynome(const Polynome& p){
        n=p.n;
        c=new double[n];
        for(int i=0; i<n; i++){
            c[i]=p.c[i];
        }
    }

    void set(int k, double a){
        if(k<n){
            c[k]=a;
        }
    }

    void show(){
        cout<<c[0];
        for(int i=1; i<n; i++){
            cout<<"+"<<c[i]<<"*x^"<<i;
        }
        cout<<"\n";
    }

    friend istream& operator>>(istream& in, Polynome& p){
        cout<<"input number of coefficients: ";
        in>>p.n;
        p.c=new double[p.n];
        cout<<"input coefficients: ";
        for(int i=0; i<p.n; i++){
            in>>p.c[i];
        }
        return in;
    }
};


int main(){
    Polynome p;
    cin>>p;
    p.show();
}