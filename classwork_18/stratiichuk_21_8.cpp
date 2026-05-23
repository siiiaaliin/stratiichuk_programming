#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
    if(argc<2){
        cout<<"no sentence given\n";
        return 0;
    }

    string sentence=argv[1];

    vector<string> words;
    string w;
    stringstream ss(sentence);
    while(ss>>w){
        words.push_back(w);
    }

    sort(words.begin(), words.end());

    do{
        for(int i=0; i<words.size(); i++){
            cout<<words[i]<<" ";
        }
        cout<<"\n";
    }while(next_permutation(words.begin(), words.end()));

    return 0;
}