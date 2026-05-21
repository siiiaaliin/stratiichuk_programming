#include <iostream>
#include <string>

using namespace std;

template <typename T>
T sum(T* x, size_t n){
    T s=x[0];
    for(size_t i=1; i<n; i++){
        s+=x[i];
    }
    return s;
}

string sum(char* x, size_t n){
    string s="";
    for(size_t i=0; i<n; i++){
        s+=x[i];
    }
    return s;
}

int* sum(int** x, size_t n){
    int* r=new int[n];
    size_t k=0;
    for(size_t i=0; i<n; i++){
        if(x[i]!=NULL){
            r[k]=x[i][0];
            k++;
        }
    }
    return r;
}


int main(){
    int v1[]={1, 2, 3};
    cout<<"sum(v1, 3)="<<sum(v1, 3)<<"\n";
    
    double v2[]={1, 2, 3};
    cout<<"sum(v2, 3)="<<sum(v2, 3)<<"\n";
    
    string v3[]={"a", "bc", "def"};
    cout<<"sum(v3, 3)="<<sum(v3, 3)<<"\n";
    
    char v4[]={'a', 'b', 'c'};
    cout<<"sum(v4, 3)="<<sum(v4, 3)<<"\n";
    
    int a1[]={1, 4};
    int a2[]={2};
    int a3[]={3};
    int* v5[]={a1, a2, a3};
    int* res=sum(v5, 3);
    cout<<"sum(v5, 3)=";
    for(size_t i=0; i<3; i++){
        std::cout<<res[i]<<" ";
    }
    cout<<"\n";
    delete[] res;
    
    return 0;
}