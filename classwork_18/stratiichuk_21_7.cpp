#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
    if(argc<2){
        cout<<"no word given\n";
        return 0;
    }

    string s=argv[1];
    sort(s.begin(), s.end());

    do{
        cout<<s<<"\n";
    }while(next_permutation(s.begin(), s.end()));

    return 0;
}