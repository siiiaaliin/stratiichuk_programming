#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream f;
    f.open("input.txt");
    int a[10000];
    int n=0;
    int num;
    char ch;
    while(f>>num){
        a[n]=num;
        n++;
        f>>ch;
    }
    f.close();

    ofstream g;
    g.open("output.txt");
    for(int i=0;i<n;i++){
        if(a[i]>0){
            g<<a[i]<<" ";
        }
    }
    g.close();
}

