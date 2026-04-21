#include <iostream>
#include <string>

using namespace std;

void mod_str(string &s){
    int first_st=s.find_first_of('.');
    int last_st=s.find_last_of('.');

    if(first_st==string::npos){
        while(s[0]==' '){
            s.erase(0,1);
        }
        return;
    }

    if(first_st==last_st){
        s.erase(0, first_st+1);
        return;
    }

    s.erase(first_st, last_st-first_st+1);
}

int main(){
    string u;
    cout<<"Enter the string: ";
    getline(cin, u);
    mod_str(u);
    cout<<"The string is: "<<u<<endl;

    return 0;
}