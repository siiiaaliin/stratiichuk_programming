#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
    int n;
    cout<<"n=";
    cin>>n;
    int* m=new int[n];
    for(int i=0; i<n; i++){
        cout<<"m["<<i<<"]=";
        cin>>m[i];
    }
    double* x=new double[n];

    char f1[]="data.txt";
    ifstream f;
    f.open(f1);
    if(f.bad()){
        cout<<"File"<<f1<<"is not opened\n";
        return -1;
    }
    for(int i=0; i<n; i++){
        if(f>>x[i]){
        }
        else{
            break;
        }
    }
    f.close();

    char f2[]="result.txt";
    ofstream g;
    g.open(f2);
    if(g.bad()){
        cout<<"File"<<f2<<"is not opened\n";
        return -1;
    }
    for(int i=0; i<n; i++){
        double z=pow(x[i], m[i]);
        g<<z<<"\n";
    }
    g.close();
    delete[] m;
    delete[] x;
}