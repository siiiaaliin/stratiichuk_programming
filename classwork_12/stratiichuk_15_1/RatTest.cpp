#include <iostream>
#include <math.h>
#include "Rat.h"

using namespace std;

int main(){
    Rational b(1,2);
    Rational c;
    c.input();
    Rational q=b.add(c);
    Rational* mass;
    int n;
    cin>>n;
    mass=new Rational[n];
    for(int i=0; i<n; i++){
        // cout<<"mass["<<i<<"]:";
        // cin>>mass[i];
        mass[i].input();
    }

    q=mass[0];
    for(int i=1; i<n; i++){
        if(mass[i].less(q)){
            q=mass[i];
        }
    }

    q.output();
    delete[] mass;
    q.save("rat.txt");

    Rational eps(1, 100);
    Rational s(0,1);
    Rational t(1,1);
    int k=1;
    while(eps.less(t)){
        if(k%2==0){
            s=s.add(t.mul(Rational(-1,1)));
        }
        else{
            s=s.add(t);
        }
        k++;
        t=Rational(1, k*k);
    }

    cout<<"s="<<s;
}