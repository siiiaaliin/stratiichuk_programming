// Histogram.h
// Стратійчук Аліна, Рябой Ангеліна (статистика 1)
// оголошення структури та функцій для роботи з гістограмою

#ifndef __HISTOGRAM_H__
#define __HISTOGRAM_H__
#include <stdio.h>


typedef struct {
    double min_hist;
    double max_hist;
    unsigned M;
    unsigned *frequency;
    unsigned total;
} Histogram;

// Аліна
int new_Histogram(Histogram *h, double min, double max, unsigned M);
void delete_Histogram(Histogram *h);

void setMin(Histogram *h, double m);
void setMax(Histogram *h, double m);
void setM(Histogram *h, unsigned m);

int addNumber(Histogram *h, double x);
int addNumberAnyway(Histogram *h, double x);
void addBatch(Histogram *h, double *data, unsigned n);

void addFromTextFile(Histogram *h, const char *filename);
void addFromBinFile(Histogram *h, const char *filename);

void input_Histogram(Histogram *h);
void print_Histogram(Histogram h);

void writeToTextFile(Histogram h, const char *filename);
void writeToBinFile(Histogram h, const char *filename);
void readFromTextFile(Histogram *h, const char *filename);
void readFromBinFile(Histogram *h, const char *filename);


// Ангеліна
unsigned num(Histogram h);
unsigned numHist(Histogram h, unsigned i);
double mean(Histogram h);
double median(Histogram h);
double variance(Histogram h);
double dev(Histogram h);

double asymmetry(Histogram h);
double kurtosis(Histogram h);
double mode(Histogram h);
double range(Histogram h);

double pearsonNormal(Histogram h);

#endif