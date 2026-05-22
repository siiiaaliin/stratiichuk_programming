#include <iostream>
#include <set>
#include <fstream>
#include <utility>

using namespace std;

int main(){
    int x;
    set<int> s1;
    do{
        cin>>x;
        if(x==0){
            break;
        }
        s1.insert(x);
    } 
    while(true);

    while(s1.size()>1){
        set<int> s2;
        set<int>::iterator m=s1.begin();
        while(m!=s1.end()){
            int y=*m;
            m++;
            if(m!=s1.end()){
                y+=*m;
                m++;
            }
            s2.insert(y);
        }
        s1=s2;        
    }
    cout<<*s1.begin()<<"\n";
    return 0;
}