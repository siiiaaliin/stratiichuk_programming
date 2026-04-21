#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int count_words(const string &s, char ch){
    stringstream u(s);
    string word;
    int count=0;
    while(u>>word){
        for(int i=0; i<word.length() ;i++){
            if(word[i]==ch){
                count++;
                break;
            }
        }
    }
    return count;
}

int main(){
    string s;
    char ch;
    cout<<"Enter a string: ";
    getline(cin,s);
    cout<<"Enter a character: ";
    cin>>ch;

    cout<<"Number of words with character: "<<count_words(s,ch)<<endl;

    return 0;
}