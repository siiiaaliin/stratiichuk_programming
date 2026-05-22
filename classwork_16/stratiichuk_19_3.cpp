#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Polynome{
    vector<T> c;
    public:
    Polynome(){}
    void input(){
        int n;
        cout<<"input n: ";
        cin>>n;
        for(int i=0; i<n; i++){
            T x;
            cout<<"input c["<<i<<"]: ";
            cin>>x;
            c.push_back(x);
        }
    }

    void output(){
        for(int i=0; i<c.size(); i++){
            cout<<c[i]<<"*x^"<<i;
            if(i!=c.size()-1){
                cout<<"+";
            }
        }
        cout<<"\n";
    }

    Polynome<T> add(Polynome<T> p){
        Polynome<T> r;
        int n1=c.size();
        int n2=p.c.size();
        int n=n1;
        if(n2>n){
            n=n2;
        }
        for(int i=0; i<n; i++){
            T x=0;
            if(i<n1){
                x+=c[i];
            }
            if(i<n2){
                x+=p.c[i];
            }
            r.c.push_back(x);
        }
        return r;
    }
    
    Polynome<T> mul(Polynome<T> p){
        Polynome<T> r;
        int n1=c.size();
        int n2=p.c.size();
        for(int i=0; i<n1+n2-1; i++){
            r.c.push_back(0);
        }
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                r.c[i+j]+=c[i]*p.c[j];
            }
        }
        return r;
    }
    
    T value(T x){
        T r=0;
        T xp=1;
        for(int i=0; i<c.size(); i++){
            r+=c[i]*xp;
            xp*=x;
        }
        return r;
    }
};

int main(){
    Polynome<int> p1;
    p1.input();
    Polynome<int> p2;
    p2.input();
    
    cout<<"p1: ";
    p1.output();
    cout<<"p2: ";
    p2.output();
    
    Polynome<int> s=p1.add(p2);
    cout<<"p1+p2: ";
    s.output();
    
    Polynome<int> m=p1.mul(p2);
    cout<<"p1*p2: ";
    m.output();
    
    cout<<"p1(2): "<<p1.value(2)<<"\n";
    
    return 0;
}