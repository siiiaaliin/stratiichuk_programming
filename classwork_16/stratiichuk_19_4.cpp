#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
    int n, m;
    cout<<"input n, m: ";
    cin>>n>>m;
    
    vector<list<int>> matrix;
    for(int i=0; i<n; i++){
        list<int> row;
        cout<<"input row "<<i<<": ";
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }
    
    vector<int> maxs;
    for(int i=0; i<n; i++){
        int mx;
        int k=0;
        for(int x : matrix[i]){
            if(k==0 || x>mx){
                mx=x;
            }
            k++;
        }
        maxs.push_back(mx);
    }
    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(maxs[j]<maxs[j+1]){
                int t=maxs[j];
                maxs[j]=maxs[j+1];
                maxs[j+1]=t;
                list<int> t2=matrix[j];
                matrix[j]=matrix[j+1];
                matrix[j+1]=t2;
            }
        }
    }
    
    cout<<"result:\n";
    for(int i=0; i<n; i++){
        for(int x : matrix[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}