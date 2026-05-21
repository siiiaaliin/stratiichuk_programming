#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vector{
    int n;
    double* arr;

public:
    Vector(int n_){
        if(n_<=0){
            throw "incorrect size";
        }
        n=n_;
        arr=new double[n];
        for(int i=0; i<n; i++){
            arr[i]=0;
        }
    }

    ~Vector(){
        delete[] arr;
    }

    void input(){
        cout<<"input "<<n<<" values: ";
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
    }

    void set(int i, double x){
        if(i<0 || i>=n){
            throw "incorrect index";
        }
        arr[i]=x;
    }

    double get(int i){
        if(i<0 || i>=n){
            throw "incorrect index";
        }
        return arr[i];
    }

    void show(){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    void readFromFile(string filename){
        ifstream f(filename);
        if(!f){
            throw "cannot open file for reading";
        }
        for(int i=0; i<n; i++){
            f>>arr[i];
        }
        f.close();
    }

    void writeToFile(string filename){
        ofstream f(filename);
        if(!f){
            throw "cannot open file for writing";
        }
        for(int i=0; i<n; i++){
            f<<arr[i]<<" ";
        }
        f.close();
    }

    double scalar_product(Vector& v){
        if(n!=v.n){
            throw "vectors have different sizes";
        }
        double s=0;
        for(int i=0; i<n; i++){
            s+=arr[i]*v.arr[i];
        }
        return s;
    }

    void cross_product(Vector& v, Vector& result){
        if(n!=3 || v.n!=3 || result.n!=3){
            throw "cross product only for size 3";
        }
        result.arr[0]=arr[1]*v.arr[2]-arr[2]*v.arr[1];
        result.arr[1]=arr[2]*v.arr[0]-arr[0]*v.arr[2];
        result.arr[2]=arr[0]*v.arr[1]-arr[1]*v.arr[0];
}
};


int main(){
    try{
        Vector v1(3);
        v1.input();

        Vector v2(3);
        v2.input();

        cout<<"v1: ";
        v1.show();
        cout<<"v2: ";
        v2.show();

        cout<<"scalar product: "<<v1.scalar_product(v2)<<"\n";

        Vector v3(3);
        v1.cross_product(v2, v3);
        cout<<"cross product: ";
        v3.show();

        cout<<"v1[1]="<<v1.get(1)<<"\n";

        v1.writeToFile("vector.txt");
        cout<<"saved to vector.txt\n";

        Vector v4(3);
        v4.readFromFile("vector.txt");
        cout<<"read from file: ";
        v4.show();
    }
    catch(const char* msg){
        cout<<"error: "<<msg<<"\n";
    }

    return 0;
}