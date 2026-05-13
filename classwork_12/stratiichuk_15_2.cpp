#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Point{
    double x, y;
    static int count;
    
    public:
    Point(){}

    void set(double a, double b){
        x=a;
        y=b;
        count++;
    }
    
    double get_x(){ 
        return x; 
    }

    double get_y(){
        return y;
    }
    
    static int counter(){
        return count;
    }
};
int Point::count=0;

int main(){
    Point points[100];
    int n=0;
    string answer;
    
    while(true){
        cout<<"ввести вершину? ";
        cin>>answer;
        if(answer=="ні"){
            break;
        }
        
        double x, y;
        cout<<"введіть координати: ";
        cin>>x>>y;
        points[n].set(x, y);
        n++;
    }
    
    cout<<"кількість введених вершин: "<<Point::counter()<<"\n";
    
    double perimeter=0;
    for(int i=0; i<n; i++){
        int next=i+1;
        if(next==n){
            next=0;
        }
        double d_x=points[next].get_x()-points[i].get_x();
        double d_y=points[next].get_y()-points[i].get_y();
        perimeter+=sqrt(d_x*d_x+d_y*d_y);
    }
    cout<<"периметр: "<<perimeter;

    return 0;
}