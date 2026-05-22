#include<iostream>
#include<vector>
#include<fstream>
#include<utility>
#include<cmath>

using namespace std;

int main(){
    ifstream f1("input.txt");
    char ch1,ch2,ch3;
    double x,y;
    vector<pair<double,double>> a;
    while(f1>>ch1>>x>>ch2>>y>>ch3){
        a.push_back(make_pair(x,y));
    }
    f1.close();

    vector<pair<double,double>> seg1;
    vector<pair<double,double>> seg2;
    vector<double> len;

    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            seg1.push_back(a[i]);
            seg2.push_back(a[j]);
            double dx=a[j].first-a[i].first;
            double dy=a[j].second-a[i].second;
            len.push_back(sqrt(dx*dx+dy*dy));
        }
    }

    for(int i=0; i<len.size(); i++){
        for(int j=i+1; j<len.size(); j++){
            if(len[i]>len[j]){
                double t=len[i];
                len[i]=len[j];
                len[j]=t;
                pair<double,double> t1=seg1[i];
                seg1[i]=seg1[j];
                seg1[j]=t1;
                pair<double,double> t2=seg2[i];
                seg2[i]=seg2[j];
                seg2[j]=t2;
            }
        }
    }

    ofstream f2("output.txt");
    for(int i=0; i<seg1.size(); i++){
        f2<<"("<<seg1[i].first<<","<<seg1[i].second<<")("<<seg2[i].first<<","<<seg2[i].second<<")\n";
    }
    f2.close();

    return 0;
}