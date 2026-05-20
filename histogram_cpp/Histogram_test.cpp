// Histogram_test.cpp
// Стратійчук Аліна, Рябой Ангеліна
// тестова програма для функцій

#include "Histogram.h"
#include <iostream>
using namespace std;

int main(){
    // input(&h);
    Histogram h(12.0, 24.0, 6);
    h.addFromTextFile("Histogram_test.txt");

    h.print();

    cout<<"\nstatistics:\n";
    cout<<"num: "<<h.num()<<"\n";
    for(unsigned i=0; i<6; i++){
        cout<<"numHist["<<i<<"]: "<<h.numHist(i)<<"\n";
    }
    cout<<"mean: "<< h.mean()<<"\n";
    cout<<"median: "<<h.median()<<"\n";
    cout<<"variance: "<<h.variance()<<"\n";
    cout<<"dev: "<<h.dev()<<"\n";
    cout<<"asymmetry: "<<h.asymmetry()<<"\n";
    cout<<"kurtosis: "<< h.kurtosis()<<"\n";
    cout<<"mode: "<<h.mode()<<"\n";
    cout<<"range: "<< h.range()<<"\n";
    cout<<"pearsonNormal: "<<h.pearsonNormal()<<"\n";

    h.writeToTextFile("Histogram_out.txt");
    h.writeToBinFile("Histogram_out.bin");

    Histogram h2;
    Histogram h3;

    h2.readFromTextFile("Histogram_out.txt");
    cout<<"\nhistogram read from text file:\n";
    h2.print();

    h3.readFromBinFile("Histogram_out.bin");
    cout<<"\nhistogram read from bin file:\n";
    h3.print();

    return 0;
}