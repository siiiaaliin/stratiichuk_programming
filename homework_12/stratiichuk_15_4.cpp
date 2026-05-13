#include <iostream>
#include <math.h>

using namespace std;

class Point{
    double x, y;
    bool empty;
    
    public:
    Point(){
        empty=true;
    }
    
    void input(){
        cout<<"введіть x і y: ";
        cin>>x>>y;
        empty=false;
    }
    
    void output(){
        if(empty){
            cout<<"порожня точка\n";
        }
        else{
            cout<<"("<<x<<", "<<y<<")\n";
        }
    }
    
    void set(double a, double b){
        x=a;
        y=b;
        empty=false;
    }
    
    double get_x(){
        return x;
    }
    
    double get_y(){
        return y;
    }
};


class Segment{
    Point p1, p2;
    
    public:
    Segment(){}
    
    void input(){
        cout<<"A:\n";
        p1.input();
        cout<<"B:\n";
        p2.input();
    }
    
    void output(){
        cout<<"відрізок: ";
        p1.output();
        p2.output();
    }
    
    void set(Point a, Point b){
        p1=a;
        p2=b;
    }
    
    Point middle(){
        double m_x=(p1.get_x()+p2.get_x())/2;
        double m_y=(p1.get_y()+p2.get_y())/2;
        Point m;
        m.set(m_x, m_y);
        return m;
    }
    
    double length(){
        double d_x=p2.get_x()-p1.get_x();
        double d_y=p2.get_y()-p1.get_y();
        return sqrt(d_x*d_x+d_y*d_y);
    }
    
    Point intersect(Segment s2){
        Point result;
        double x1=p1.get_x(), y1=p1.get_y();
        double x2=p2.get_x(), y2=p2.get_y();
        double x3=s2.p1.get_x(), y3=s2.p1.get_y();
        double x4=s2.p2.get_x(), y4=s2.p2.get_y();

        double den=-(x2-x1)*(y4-y3)+(x4-x3)*(y2-y1);
        if(den==0){
            return result;
        }
        double s=(-(x3-x1)*(y4-y3)+(x4-x3)*(y3-y1))/den;
        double t=((x2-x1)*(y3-y1)-(x1-x3)*(y2-y1))/den;
        if(s>=0 && s<=1 && t>=0 && t<=1){
            double x_0=x1+s*(x2-x1);
            double y_0=y1+s*(y2-y1);
            result.set(x_0, y_0);
        }
        return result;
    }
};


class Triangle{
    Point a, b, c;
    
    public:
    Triangle(){}
    
    void input(){
        cout<<"А:\n";
        a.input();
        cout<<"B:\n";
        b.input();
        cout<<"C:\n";
        c.input();
    }
    
    void output(){
        cout<<"трикутник:\n";
        cout<<"A="; a.output();
        cout<<"B="; b.output();
        cout<<"C="; c.output();
    }
    
    double perimeter(){
        Segment ab, bc, ca;
        ab.set(a, b);
        bc.set(b, c);
        ca.set(c, a);
        return ab.length()+bc.length()+ca.length();
    }
    
    double area(){
        double x1=a.get_x(), y1=a.get_y();
        double x2=b.get_x(), y2=b.get_y();
        double x3=c.get_x(), y3=c.get_y();
        double s=0.5*abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3);
        return s;
    }
};


int main(){
    Segment s1;
    s1.input();
    cout<<"середина відрізка: ";
    s1.middle().output();
    cout<<"довжина відрізка: "<<s1.length()<<"\n";
    
    Segment s2;
    s2.input();
    cout<<"точка перетину відрізків: ";
    s1.intersect(s2).output();

    Triangle t;
    t.input();
    cout<<"периметр: "<<t.perimeter()<<"\n";
    cout<<"площа: "<<t.area()<<"\n";
    
    return 0;
}