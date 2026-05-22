#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> input_vector(int dim){
    vector<double> b;
    for(int i=0; i<dim; i++){
        double c;
        cin>>c;
        b.push_back(c);
    }
    return b;
}

double norma(const vector<double>&d){
    double f=0;
    for(double g:d){
        f+=g*g;
    }
    return sqrt(f);
}

double sum_norma(const vector<vector<double>>& a){
    double p=0;
    for(const vector<double>q:a){
        p+=norma(q);
    }
    return p;
}

int main(){
    int n, d;
    cout<<"input n, d: ";
    cin>>n>>d;
    vector<vector<double>> s;
    for(int i=0; i<n; i++){
        vector<double> z=input_vector(d);
        s.push_back(z);
    }
    cout<<"sum norma: "<<sum_norma(s);

    return 0;
}
    