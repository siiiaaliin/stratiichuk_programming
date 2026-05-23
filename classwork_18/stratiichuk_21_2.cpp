#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    list<int> l;
    int a;
    cout<<"enter list of num: ";
    while(cin>>a){
        l.push_back(a);
        if(getchar()=='\n'){
            break;
        }
    }

    int x;
    cout<<"enter x: ";
    cin>>x;

    partition(l.begin(), l.end(), [&x](int i){return i<=x;});

    cout<<"result: ";
    for(list<int>::iterator it=l.begin(); it!=l.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"\n";

    return 0;
}