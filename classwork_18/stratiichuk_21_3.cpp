#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int sum_max(vector<int> v, int k){
    if(k>v.size()){
        return 0;
    }
    sort(v.begin(), v.end());
    return accumulate(v.end()-k, v.end(), 0);
}

vector<int> min_arr(vector<int> v, int k){
    vector<int> r;
    if(k>v.size()){
        return r;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<k; i++){
        r.push_back(v[i]);
    }
    return r;
}

int main(){
    vector<int> v;
    int a;
    cout<<"enter vector of num: ";
    while(cin>>a){
        v.push_back(a);
        if(getchar()=='\n'){
            break;
        }
    }

    int k;
    cout<<"enter k: ";
    cin>>k;

    cout<<"sum of "<<k<<" max: "<<sum_max(v, k)<<"\n";

    vector<int> r=min_arr(v, k);
    cout<<k<<" min: ";
    for(int i=0; i<r.size(); i++){
        cout<<r[i]<<" ";
    }
    cout<<"\n";

    return 0;
}