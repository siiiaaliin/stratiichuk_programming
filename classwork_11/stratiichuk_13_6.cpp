#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int shortest_word(const string &s){
    stringstream u(s);
    string word;
    int min_length=INT_MAX;
    while(u>>word){
        if(word.length()<=min_length){
            min_length=word.length();
        }
    }
    return min_length;
}

string first_shortest(const string &s){
    stringstream u(s);
    string word;
    int min_length=shortest_word(s);
    while(u>>word){
        if(word.length()==min_length){
            return word;
        }
    }
    return "";
}

string last_shortest(const string &s){
    stringstream u(s);
    string word;
    string last="";
    int min_length=shortest_word(s);
    while(u>>word){
        if(word.length()==min_length){
            last=word;
        }
    }
    return last;
}

string all_shortest(const string &s){
    stringstream u(s);
    string word;
    string result="";
    int min_length=shortest_word(s);
    while(u>>word){
        if(word.length()==min_length){
            result+=word+" ";
        }
    }
    return result;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);

    cout<<"first shortest word: "<<first_shortest(s)<<endl;
    cout<<"last shortest word: "<<last_shortest(s)<<endl;
    cout<<"all shortest words: "<<all_shortest(s)<<endl;

    return 0;
}