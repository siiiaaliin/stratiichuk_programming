#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
    string s;
    cout<<"enter string: ";
    getline(cin, s);

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    cout<<"result: "<<s<<"\n";

    return 0;
}