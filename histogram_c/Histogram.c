// Histogram.c
// Стратійчук Аліна, Рябой Ангеліна (статистика 1)
// реалізація функцій для роботи з гістограмою

#include "Histogram.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


// Аліна
int new_Histogram(Histogram *h, double min, double max, unsigned M){
    if (max<=min){
        printf("max should be bigger than min\n");
        return 1;
    }
    if (M==0){
        printf("M cannot be zero\n");
        return 1;
    }
    h->min_hist=min;
    h->max_hist=max;
    h->M=M;
    h->frequency=(unsigned*)calloc(M, sizeof(unsigned));
    h->total=0;
    return 0;
}

void delete_Histogram(Histogram *h){
    free(h->frequency);
}

void setMin(Histogram *h, double m){
    h->min_hist=m;
}

void setMax(Histogram *h, double m){
    h->max_hist=m;
}

void setM(Histogram *h, unsigned m){
    free(h->frequency);
    h->frequency=(unsigned*)calloc(m, sizeof(unsigned));
    h->M=m;
    h->total=0;
}

int addNumber(Histogram *h, double x){
    unsigned idx;
    double width=(h->max_hist-h->min_hist)/h->M;
    if (x<h->min_hist || x>=h->max_hist){
        return 1;
    }
    idx=(unsigned)((x-h->min_hist)/width);
    h->frequency[idx]++;
    h->total++;
    return 0;
}

int addNumberAnyway(Histogram *h, double x){
    unsigned idx;
    double width=(h->max_hist-h->min_hist)/h->M;
    if (x<h->min_hist){
        idx=0;
    } 
    else if (x>=h->max_hist){
        idx=h->M-1;
    } 
    else {
        idx=(unsigned)((x-h->min_hist)/width);
    }
    h->frequency[idx]++;
    h->total++;
    return 0;
}

void addBatch(Histogram *h, double *data, unsigned n){
    for (unsigned i=0; i<n; i++){
        addNumber(h, data[i]);
    }
}

void addFromTextFile(Histogram *h, const char *filename){
    FILE *f=fopen(filename, "r");
    double x;
    while (fscanf(f, "%lf", &x)==1){
        addNumber(h, x);
    }
    fclose(f);
}

void addFromBinFile(Histogram *h, const char *filename){
    FILE *f=fopen(filename, "rb");
    double x;
    while (fread(&x, sizeof(double), 1, f)==1){
        addNumber(h, x);
    }
    fclose(f);
}

void input_Histogram(Histogram *h){
    double min, max;
    unsigned m;
    printf("еnter min_hist: "); 
    scanf("%lf", &min);
    printf("еnter max_hist: "); 
    scanf("%lf", &max);
    printf("еnter number of columns M: "); 
    scanf("%u", &m);
    new_Histogram(h, min, max, m);
}

void print_Histogram(Histogram h){
    unsigned i;
    double width=(h.max_hist-h.min_hist)/h.M;
    printf("min=%.2f, max=%.2f, M=%u, total=%u\n", h.min_hist, h.max_hist, h.M, h.total);
    printf("i  left  right  frequency\n");
    for (i=0; i<h.M; i++){
        double a=h.min_hist+i*width;
        printf("%u  %.2f  %.2f  %u\n", i, a, a+width, h.frequency[i]);
    }
}

void writeToTextFile(Histogram h, const char *filename){
    FILE *f=fopen(filename, "w");
    fprintf(f, "%.10f %.10f %u %u\n", h.min_hist, h.max_hist, h.M, h.total);
    for (unsigned i=0; i<h.M; i++){
        fprintf(f, "%u\n", h.frequency[i]);
    }
    fclose(f);
}

void writeToBinFile(Histogram h, const char *filename){
    FILE *f=fopen(filename, "wb");
    fwrite(&h.min_hist, sizeof(double), 1, f);
    fwrite(&h.max_hist, sizeof(double), 1, f);
    fwrite(&h.M, sizeof(unsigned), 1, f);
    fwrite(&h.total, sizeof(unsigned), 1, f);
    fwrite(h.frequency, sizeof(unsigned), h.M, f);
    fclose(f);
}

void readFromTextFile(Histogram *h, const char *filename){
    FILE *f=fopen(filename, "r");
    double min, max;
    unsigned m, t;
    fscanf(f, "%lf %lf %u %u", &min, &max, &m, &t);
    new_Histogram(h, min, max, m);
    h->total=t;
    for (unsigned i=0; i<m; i++){
        fscanf(f, "%u", &h->frequency[i]);
    }
    fclose(f);
}

void readFromBinFile(Histogram *h, const char *filename){
    FILE *f=fopen(filename, "rb");
    double min, max;
    unsigned m, t;
    fread(&min, sizeof(double), 1, f);
    fread(&max, sizeof(double), 1, f);
    fread(&m, sizeof(unsigned), 1, f);
    fread(&t, sizeof(unsigned), 1, f);
    new_Histogram(h, min, max, m);
    h->total=t;
    fread(h->frequency, sizeof(unsigned), m, f);
    fclose(f);
}


// Ангеліна
unsigned num(Histogram h){
    return h.total;
}

unsigned numHist(Histogram h, unsigned i){
    return h.frequency[i];
}

double mean(Histogram h){
    double width=(h.max_hist-h.min_hist)/h.M;
    double s=0;
    double left;
    double right;
    double c;
    for(unsigned i=0; i<h.M; i++){
        left=h.min_hist+i*width;
        right=h.min_hist+(i+1)*width;
        c=(left+right)/2;
        s+=c*h.frequency[i];
    }
    return s/h.total;
}

double median(Histogram h){
    double width=(h.max_hist-h.min_hist)/h.M;
    unsigned half=h.total/2;
    unsigned F=0;
    double L; 
    for(unsigned i=0; i<h.M; i++){
        if(F+h.frequency[i]>half){
            L=h.min_hist+i*width;
            return L+((double)(half-F)/h.frequency[i])*width;
        }
        F+=h.frequency[i];
    }
    return h.max_hist;
}

double dev(Histogram h){
    double width=(h.max_hist-h.min_hist)/h.M;
    double m=mean(h);
    double s=0;
    double left;
    double right;
    double c;
    double diff;
    for(unsigned i=0; i<h.M; i++){
        left=h.min_hist+i*width;
        right=h.min_hist+(i+1)*width;
        c=(left+right)/2;
        diff=c-m;
        if(diff<0){
            diff=-diff;
        }
        s+=h.frequency[i]*diff;
    }
    return s/h.total;
}

double variance(Histogram h){
    double width=(h.max_hist-h.min_hist)/h.M;
    double m=mean(h);
    double s=0;
    double left;
    double right;
    double c;
    for(unsigned i=0; i<h.M; i++){
        left=h.min_hist+i*width;
        right=h.min_hist+(i+1)*width;
        c=(left+right)/2;
        s+=h.frequency[i]*(c-m)*(c-m);
    }
    return s/h.total;
}

double asymmetry(Histogram h){
    double width=(h.max_hist-h.min_hist)/h.M;
    double m=mean(h);
    double sigma=sqrt(variance(h));
    double s=0;
    double left;
    double right;
    double c;
    double mu3;
    for(unsigned i=0; i<h.M; i++){
        left=h.min_hist+i*width;
        right=h.min_hist+(i+1)*width;
        c=(left+right)/2;
        s+=h.frequency[i]*(c-m)*(c-m)*(c-m);
    }
    mu3=s/h.total;
    return mu3/(sigma*sigma*sigma);
}

double kurtosis(Histogram h){
    double width=(h.max_hist-h.min_hist)/h.M;
    double m=mean(h);
    double sigma=sqrt(variance(h));
    double s=0;
    double left;
    double right;
    double c;
    double mu4;
    for(unsigned i=0; i<h.M; i++){
        left=h.min_hist+i*width;
        right=h.min_hist+(i+1)*width;
        c=(left+right)/2;
        s+=h.frequency[i]*(c-m)*(c-m)*(c-m)*(c-m);
    }
    mu4=s/h.total;
    return mu4/(sigma*sigma*sigma*sigma)-3;
}

double mode(Histogram h){
    unsigned best=0;
    double width;
    double left;
    unsigned n_mode;
    unsigned n_prev;
    unsigned n_next;
    double numerator;
    double denominator;
    for(unsigned i=1; i<h.M; i++){
        if(h.frequency[i]>h.frequency[best]){
            best=i;
        }
    }
    width=(h.max_hist-h.min_hist)/h.M;
    left=h.min_hist+best*width;
    n_mode=h.frequency[best];
    if(best>0){
        n_prev=h.frequency[best-1];
    }
    else{
        n_prev=0;
    }
    if(best<h.M-1){
        n_next=h.frequency[best+1];
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

double range(Histogram h){
    return h.max_hist-h.min_hist;
}

double pearsonNormal(Histogram h){
    double width=(h.max_hist-h.min_hist)/h.M;
    double m=mean(h);
    double sigma=sqrt(variance(h));
    double expected[h.M];
    double left;
    double right;
    double z_left;
    double z_right;
    double phi_left;
    double phi_right;
    double p;
    double s=0;
    double diff;
    for(unsigned i=0; i<h.M; i++){
        left=h.min_hist+i*width;
        right=h.min_hist+(i+1)*width;
        z_left=(left-m)/sigma;
        z_right=(right-m)/sigma;
        phi_left=0.5*erf(z_left/sqrt(2.0));
        phi_right=0.5*erf(z_right/sqrt(2.0));
        if(i==0){
            phi_left=-0.5;
        }
        if(i==h.M-1){
            phi_right=0.5;
        }
        p=phi_right-phi_left;
        expected[i]=h.total*p;
    }
    for(unsigned i=0; i<h.M; i++){
        if(expected[i]<=0){
            continue;
        }
        diff=h.frequency[i]-expected[i];
        s+=diff*diff/expected[i];
    }
    return s;
}