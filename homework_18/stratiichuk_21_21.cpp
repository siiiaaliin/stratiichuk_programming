#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;
    int a;
    cout<<"enter numbers, 0 to stop:\n";
    while(cin>>a){
        if(a==0){
            break;
        }
        v.push_back(a);
    }

    int k;
    cout<<"enter k: ";
    cin>>k;

    vector<int> v1=v;
    sort(v1.begin(), v1.end());
    cout<<"sort: ";
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    cout<<"\n";

    vector<int> v2=v;
    partial_sort(v2.begin(), v2.begin()+k, v2.end());
    cout<<"partial_sort: ";
    for(int i=0; i<v2.size(); i++){
        cout<<v2[i]<<" ";
    }
    cout<<"\n";

    vector<int> v3=v;
    nth_element(v3.begin(), v3.begin()+k, v3.end());
    cout<<"nth_element: ";
    for(int i=0; i<v3.size(); i++){
        cout<<v3[i]<<" ";
    }
    cout<<"\n";

    return 0;
}