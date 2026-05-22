#include <iostream>
#include <deque>
#include <fstream>

using namespace std;

int main(){
    ifstream f("input.txt");
    if(!f){
        cout<<"cannot open file";
        return 0;
    }

    deque<int> d;
    int x;
    while(f>>x){
        d.push_back(x);
    }
    f.close();

    cout<<"deque: ";
    for(int i=0; i<d.size(); i++){
        cout<<d[i]<<" ";
    }
    cout<<"\n";

    int n=d.size();
    if(n%2==1){
        d.erase(d.begin()+n/2);
    }
    else{
        d.erase(d.begin()+n/2);
        d.erase(d.begin()+n/2-1);
    }

    cout<<"result: ";
    for(int i=0; i<d.size(); i++){
        cout<<d[i]<<" ";
    }
    cout<<"\n";

    return 0;
}