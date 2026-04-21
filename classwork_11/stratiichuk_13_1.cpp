#include <iostream>
#include <string>

using namespace std;

string return_string(string s){
    int n;
    n=s.length();
    int i=0;
    int k=-1;
    while(i<n){
        if(s[i]==':'){
            k=i;
            break;
        }
        else{
            i++;
        }
    }

    if(k==-1){
        return s;
    }

    i=n-1;
    while(i>=0){
        if(s[i]==','){
            break;
        }
        else{
            i--;
        }
    }
    return s.substr(k+1,i-k-1);
}   

int main()
{
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);

    cout<<"The string is: "<<return_string(s)<<endl;
    
    return 0;
}