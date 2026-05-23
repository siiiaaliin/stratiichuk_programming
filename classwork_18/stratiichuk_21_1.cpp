#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BoolVector{
    vector<bool> v;
    public:
    BoolVector(){}
    void input(int n){
        int x;
        for(int i=0; i<n; i++){
            cin>>x;
            v.push_back(x);
        }
    }
    void output(){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    BoolVector con(BoolVector& b){
        BoolVector r;
        for(int i=0; i<v.size(); i++){
            r.v.push_back(v[i] && b.v[i]);
        }
        return r;
    }
    BoolVector dis(BoolVector& b){
        BoolVector r;
        for(int i=0; i<v.size(); i++){
            r.v.push_back(v[i] || b.v[i]);
        }
        return r;
    }
    BoolVector neg(){
        BoolVector r;
        for(int i=0; i<v.size(); i++){
            r.v.push_back(!v[i]);
        }
        return r;
    }
    int ones(){
        return count(v.begin(), v.end(), 1);
    }
    int zeros(){
        return count(v.begin(), v.end(), 0);
    }
};

int main(){
    BoolVector a, b;
    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<"enter a: ";
    a.input(n);
    cout<<"enter b: ";
    b.input(n);

    cout<<"conjunction: ";
    a.con(b).output();
    cout<<"disjunction: ";
    a.dis(b).output();
    cout<<"negation: ";
    a.neg().output();

    cout<<"ones: "<<a.ones()<<"\n";
    cout<<"zeros: "<<a.zeros()<<"\n";

    return 0;
}