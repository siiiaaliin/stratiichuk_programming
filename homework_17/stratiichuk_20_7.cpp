#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, m;
    cout<<"input n, m: ";
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout<<"input grid:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    multiset<set<pair<int,int>>> shapes;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                vector<pair<int,int>> figure;
                figure.push_back(make_pair(i, j));
                grid[i][j]=0;

                for(int k=0; k<figure.size(); k++){
                    int x=figure[k].first;
                    int y=figure[k].second;

                    if(x+1<n && grid[x+1][y]==1){
                        grid[x+1][y]=0;
                        figure.push_back(make_pair(x+1, y));
                    }
                    if(x-1>=0 && grid[x-1][y]==1){
                        grid[x-1][y]=0;
                        figure.push_back(make_pair(x-1, y));
                    }
                    if(y+1<m && grid[x][y+1]==1){
                        grid[x][y+1]=0;
                        figure.push_back(make_pair(x, y+1));
                    }
                    if(y-1>=0 && grid[x][y-1]==1){
                        grid[x][y-1]=0;
                        figure.push_back(make_pair(x, y-1));
                    }
                }

                int minx=figure[0].first;
                int miny=figure[0].second;
                for(int k=0; k<figure.size(); k++){
                    if(figure[k].first<minx){
                        minx=figure[k].first;
                    }
                    if(figure[k].second<miny){
                        miny=figure[k].second;
                    }
                }

                set<pair<int,int>> norm;
                for(int k=0; k<figure.size(); k++){
                    norm.insert(make_pair(figure[k].first-minx, figure[k].second-miny));
                }

                shapes.insert(norm);
            }
        }
    }

    set<set<pair<int,int>>> different;
    for(multiset<set<pair<int,int>>>::iterator it=shapes.begin(); it!=shapes.end(); it++){
        different.insert(*it);
    }

    cout<<"total figures: "<<shapes.size()<<"\n";
    cout<<"different figures: "<<different.size()<<"\n";

    return 0;
}