#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    cout<<"input n: ";
    cin>>n;
    vector<string> v;
    for(int i=0; i<n; i++){
        string w;
        cout<<"input word: ";
        cin>>w;
        v.push_back(w);
    }

    multimap<char, string> m;
    for(int i=0; i<v.size(); i++){
        char key;
        if(v[i].size()>1){
            key=v[i][1];
        }
        else{
            key=v[i][0];
        }
        m.insert(make_pair(key, v[i]));
    }

    for(multimap<char, string>::iterator it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<" "<<it->second<<"\n";
    }

    return 0;
}