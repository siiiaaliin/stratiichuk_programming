// Histogram.h
// Стратійчук Аліна, Рябой Ангеліна (статистика 1)
// оголошення класу Histogram для роботи з гістограмою

#ifndef __HISTOGRAM_H__
#define __HISTOGRAM_H__
#include <iostream>
#include <fstream>

using namespace std;


class Histogram{
    double min_hist;
    double max_hist;
    unsigned M;
    unsigned* frequency;
    unsigned total;

    public:
    Histogram(double min, double max, unsigned m){
        min_hist=min;
        max_hist=max;
        M=m;
        frequency=new unsigned[m];
        for(unsigned i=0; i<m; i++){
            frequency[i]=0;
        }
        total=0;
    }

    Histogram(){
        frequency=NULL;
        min_hist=0;
        max_hist=0;
        M=0;
        total=0;
    }
    
    ~Histogram(){
        delete[] frequency;
    }

    // Аліна
    void setMin(double m);
    void setMax(double m);
    void setM(unsigned m);

    int addNumber(double x);
    int addNumberAnyway(double x);
    void addBatch(double* data, unsigned n);

    void addFromTextFile(const char* filename);
    void addFromBinFile(const char* filename);

    void input();
    void print();

    void writeToTextFile(const char* filename);
    void writeToBinFile(const char* filename);
    void readFromTextFile(const char* filename);
    void readFromBinFile(const char* filename);

    // Ангеліна
    unsigned num();
    unsigned numHist(unsigned i);
    double mean();
    double median();
    double variance();
    double dev();

    double asymmetry();
    double kurtosis();
    double mode();
    double range();

    double pearsonNormal();
};

#endif