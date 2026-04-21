#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string remove_last(const string &s){
    stringstream u(s);
    string word;
    string result="";
    while(u>>word){
        word[word.length()-1]=' ';
        result+=word;
    }
    return result;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);

    cout<<"The string is: "<<remove_last(s)<<endl;

    return 0;
}