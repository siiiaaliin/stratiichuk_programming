// Histogram.cpp
// Стратійчук Аліна, Рябой Ангеліна (статистика 1)
// реалізація методів класу Histogram

#include "Histogram.h"
#include <iostream>
#include <cmath>


// Аліна
void Histogram::setMin(double m){
    min_hist=m;
}

void Histogram::setMax(double m){
    max_hist=m;
}

void Histogram::setM(unsigned m){
    delete[] frequency;
    frequency=new unsigned[m];
    for(unsigned i=0; i<m; i++){
        frequency[i]=0;
    }
    M=m;
    total=0;
}

int Histogram::addNumber(double x){
    unsigned idx;
    double width=(max_hist-min_hist)/M;
    if (x<min_hist || x>=max_hist){
        return 1;
    }
    idx=(unsigned)((x-min_hist)/width);
    frequency[idx]++;
    total++;
    return 0;
}

int Histogram::addNumberAnyway(double x){
    unsigned idx;
    double width=(max_hist-min_hist)/M;
    if (x<min_hist){
        idx=0;
    }
    else if (x>=max_hist){
        idx=M-1;
    }
    else {
        idx=(unsigned)((x-min_hist)/width);
    }
    frequency[idx]++;
    total++;
    return 0;
}

void Histogram::addBatch(double* data, unsigned n){
    for(unsigned i=0; i<n; i++){
        addNumber(data[i]);
    }
}

void Histogram::addFromTextFile(const char* filename){
    ifstream f(filename);
    double x;
    while (f>>x){
        addNumber(x);
    }
    f.close();
}

void Histogram::addFromBinFile(const char* filename){
    ifstream f(filename, ios::binary);
    double x;
    while (f.read((char*)&x, sizeof(double))){
        addNumber(x);
    }
    f.close();
}

void Histogram::input(){
    double min, max;
    unsigned m;
    cout<<"enter min_hist: ";
    cin>>min;
    cout<<"enter max_hist: ";
    cin>>max;
    cout<<"enter M: ";
    cin>>m;
    setMin(min);
    setMax(max);
    setM(m);
}

void Histogram::print(){
    double width=(max_hist-min_hist)/M;
    cout<<"min="<<min_hist<<", max="<<max_hist<<", M="<<M<<", total="<<total<<"\n";
    cout<<"i  left  right  frequency\n";
    for(unsigned i=0; i<M; i++){
        double a=min_hist+i*width;
        cout<<i<<"  "<<a<<"  "<<a+width<<"  "<<frequency[i]<<"\n";
    }
}

void Histogram::writeToTextFile(const char* filename){
    ofstream f(filename);
    f<<min_hist<<" "<<max_hist<<" "<<M<<" "<<total<<"\n";
    for(unsigned i=0; i<M; i++){
        f<<frequency[i]<<"\n";
    }
    f.close();
}

void Histogram::writeToBinFile(const char* filename){
    ofstream f(filename, ios::binary);
    f.write((char*)&min_hist, sizeof(double));
    f.write((char*)&max_hist, sizeof(double));
    f.write((char*)&M, sizeof(unsigned));
    f.write((char*)&total, sizeof(unsigned));
    f.write((char*)frequency, sizeof(unsigned)*M);
    f.close();
}

void Histogram::readFromTextFile(const char* filename){
    ifstream f(filename);
    double min, max;
    unsigned m, t;
    f>>min>>max>>m>>t;
    setMin(min);
    setMax(max);
    setM(m);
    total=t;
    for(unsigned i=0; i<m; i++){
        f>>frequency[i];
    }
    f.close();
}

void Histogram::readFromBinFile(const char* filename){
    ifstream f(filename, ios::binary);
    double min, max;
    unsigned m, t;
    f.read((char*)&min, sizeof(double));
    f.read((char*)&max, sizeof(double));
    f.read((char*)&m, sizeof(unsigned));
    f.read((char*)&t, sizeof(unsigned));
    setMin(min);
    setMax(max);
    setM(m);
    total=t;
    f.read((char*)frequency, sizeof(unsigned)*m);
    f.close();
}


// Ангеліна
unsigned Histogram::num(){
    return total;
}

unsigned Histogram::numHist(unsigned i){
    return frequency[i];
}

double Histogram::mean(){
    double width=(max_hist-min_hist)/M;
    double s=0;
    double left;
    double right;
    double c;
    for(unsigned i=0; i<M; i++){
        left=min_hist+i*width;
        right=min_hist+(i+1)*width;
        c=(left+right)/2;
        s+=c*frequency[i];
    }
    return s/total;
}

double Histogram::median(){
    double width=(max_hist-min_hist)/M;
    unsigned half=total/2;
    unsigned F=0;
    double L;
    for(unsigned i=0; i<M; i++){
        if(F+frequency[i]>half){
            L=min_hist+i*width;
            return L+((double)(half-F)/frequency[i])*width;
        }
        F+=frequency[i];
    }
    return max_hist;
}

double Histogram::dev(){
    double width=(max_hist-min_hist)/M;
    double m=mean();
    double s=0;
    double left;
    double right;
    double c;
    double diff;
    for(unsigned i=0; i<M; i++){
        left=min_hist+i*width;
        right=min_hist+(i+1)*width;
        c=(left+right)/2;
        diff=c-m;
        if(diff<0){
            diff=-diff;
        }
        s+=frequency[i]*diff;
    }
    return s/total;
}

double Histogram::variance(){
    double width=(max_hist-min_hist)/M;
    double m=mean();
    double s=0;
    double left;
    double right;
    double c;
    for(unsigned i=0; i<M; i++){
        left=min_hist+i*width;
        right=min_hist+(i+1)*width;
        c=(left+right)/2;
        s+=frequency[i]*(c-m)*(c-m);
    }
    return s/total;
}

double Histogram::asymmetry(){
    double width=(max_hist-min_hist)/M;
    double m=mean();
    double sigma=sqrt(variance());
    double s=0;
    double left;
    double right;
    double c;
    double mu3;
    for(unsigned i=0; i<M; i++){
        left=min_hist+i*width;
        right=min_hist+(i+1)*width;
        c=(left+right)/2;
        s+=frequency[i]*(c-m)*(c-m)*(c-m);
    }
    mu3=s/total;
    return mu3/(sigma*sigma*sigma);
}

double Histogram::kurtosis(){
    double width=(max_hist-min_hist)/M;
    double m=mean();
    double sigma=sqrt(variance());
    double s=0;
    double left;
    double right;
    double c;
    double mu4;
    for(unsigned i=0; i<M; i++){
        left=min_hist+i*width;
        right=min_hist+(i+1)*width;
        c=(left+right)/2;
        s+=frequency[i]*(c-m)*(c-m)*(c-m)*(c-m);
    }
    mu4=s/total;
    return mu4/(sigma*sigma*sigma*sigma)-3;
}

double Histogram::mode(){
    unsigned best=0;
    double width;
    double left;
    unsigned n_mode;
    unsigned n_prev;
    unsigned n_next;
    double numerator;
    double denominator;
    for(unsigned i=1; i<M; i++){
        if(frequency[i]>frequency[best]){
            best=i;
        }
    }
    width=(max_hist-min_hist)/M;
    left=min_hist+best*width;
    n_mode=frequency[best];
    if(best>0){
        n_prev=frequency[best-1];
    }
    else{
        n_prev=0;
    }
    if(best<M-1){
        n_next=frequency[best+1];
    }
    else{
        n_next=0;
    }
    numerator=(double)n_mode-n_prev;
    denominator=2.0*n_mode-n_prev-n_next;
    if(denominator==0){
        return left+width/2;
    }
    return left+(numerator/denominator)*width;
}

double Histogram::range(){
    return max_hist-min_hist;
}

double Histogram::pearsonNormal(){
    double width=(max_hist-min_hist)/M;
    double m=mean();
    double sigma=sqrt(variance());
    double expected[M];
    double left;
    double right;
    double z_left;
    double z_right;
    double phi_left;
    double phi_right;
    double p;
    double s=0;
    double diff;
    for(unsigned i=0; i<M; i++){
        left=min_hist+i*width;
        right=min_hist+(i+1)*width;
        z_left=(left-m)/sigma;
        z_right=(right-m)/sigma;
        phi_left=0.5*erf(z_left/sqrt(2.0));
        phi_right=0.5*erf(z_right/sqrt(2.0));
        if(i==0){
            phi_left=-0.5;
        }
        if(i==M-1){
            phi_right=0.5;
        }
        p=phi_right-phi_left;
        expected[i]=total*p;
    }
    for(unsigned i=0; i<M; i++){
        if(expected[i]<=0){
            continue;
        }
        diff=frequency[i]-expected[i];
        s+=diff*diff/expected[i];
    }
    return s;
}