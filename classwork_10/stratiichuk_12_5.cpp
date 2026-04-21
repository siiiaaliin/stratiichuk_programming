#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
    unsigned long long a[10000];
    int n=0;
    ifstream f("input.txt");
    while(f>>a[n]){
        n++;
    }
    f.close();

    for(int i=n-1; i>=0; i--){
        double z=sqrt(a[i]);
        cout<<fixed;
        cout.precision(3);
        cout<<z<<endl;
    }
}