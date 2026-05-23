#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Sum{
public:
    T s;
    Sum(){
        s=0;
    }
    void operator()(T x){
        s=s+x;
    }
};

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

    Sum<int> sum;
    sum=for_each(v.begin(), v.end(), sum);

    cout<<"sum: "<<sum.s<<"\n";

    return 0;
}