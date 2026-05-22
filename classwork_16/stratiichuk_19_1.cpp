#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cout<<"input n: ";
    cin>>n;
    queue<int> q;

    for(int i=0; i<n; i++){
        int t;
        cout<<"input t: ";
        cin>>t;
        q.push(t);
    }

    int sum_time=0;
    int min_time=0;
    int counter=0;
    vector<int> c;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        sum_time+=t;
        counter++;
        int d=sum_time-counter+1;
        c.push_back(d);
    }

    auto b=minmax_element(c.begin(), c.end());
    cout<<*b.first<<" "<<*b.second;

    return 0;
}
