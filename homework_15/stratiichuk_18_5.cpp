// в)

#include <iostream>
using namespace std;

namespace m{
    template<typename T>
    class Mass{
        T* a;
        int n;
        
        public:
        Mass(int n_){
            n=n_;
            a=new T[n];
        }
        
        ~Mass(){
            delete[] a;
        }
        
        void input(){
            for(int i=0; i<n; i++){
                cout<<"input a["<<i<<"]: ";
                cin>>a[i];
            }
        }
        
        void output(){
            for(int i=0; i<n; i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
        
        void sort(){
            for(int i=0; i<n-1; i++){
                int min=i;
                for(int j=i+1; j<n; j++){
                    if(a[j]<a[min]){
                        min=j;
                    }
                }
                T t=a[i];
                a[i]=a[min];
                a[min]=t;
            }
        }
        
        static void sort_static(T* a, int n){
            for(int i=0; i<n-1; i++){
                int min=i;
                for(int j=i+1; j<n; j++){
                    if(a[j]<a[min]){
                        min=j;
                    }
                }
                T t=a[i];
                a[i]=a[min];
                a[min]=t;
            }
        }
    };
}


int main(){
    m::Mass<int> mass(5);
    mass.input();
    cout<<"before sort: ";
    mass.output();
    mass.sort();
    cout<<"after sort: ";
    mass.output();
    
   
    int arr[5]={5, 3, 8, 1, 4};
    cout<<"\nstatic sort\n";
    cout<<"before: ";
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    m::Mass<int>::sort_static(arr, 5);
    cout<<"after: ";
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}
