#include <map>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    map<string, int> m;
    string w;
    ifstream f("text.txt");
    while(f>>w){
        map<string, int>::iterator it=m.find(w);
        if(it==m.end()){
            m[w]=1;
        }
        else{
            it->second++;
        }
    }

    for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}