// Histogram_test.c
// Стратійчук Аліна, Рябой Ангеліна
// тестова програма для функцій

#include "Histogram.h"
#include <stdio.h>

int main(){
    Histogram h;

    // input_Histogram(&h);
    new_Histogram(&h, 12.0, 24.0, 6);
    addFromTextFile(&h, "Histogram_test.txt");

    print_Histogram(h);

    printf("\nstatistics:\n");
    printf("num: %u\n", num(h));
    for(unsigned i=0; i<h.M; i++){
        printf("numHist[%u]: %u\n", i, numHist(h, i));
    }
    printf("mean: %.4f\n", mean(h));
    printf("median: %.4f\n", median(h));
    printf("variance: %.4f\n", variance(h));
    printf("dev: %.4f\n", dev(h));
    printf("asymmetry: %.4f\n", asymmetry(h));
    printf("kurtosis: %.4f\n", kurtosis(h));
    printf("mode: %.4f\n", mode(h));
    printf("range:  %.4f\n", range(h));
    printf("pearsonNormal: %.4f\n", pearsonNormal(h));

    writeToTextFile(h, "Histogram_out.txt");
    writeToBinFile(h, "Histogram_out.bin");

    Histogram h2;
    Histogram h3;

    readFromTextFile(&h2, "Histogram_out.txt");
    printf("\nhistogram read from text file:\n");
    print_Histogram(h2);

    readFromBinFile(&h3, "Histogram_out.bin");
    printf("\nhistogram read from bin file:\n");
    print_Histogram(h3);

    delete_Histogram(&h);
    delete_Histogram(&h2);
    delete_Histogram(&h3);
    return 0;
}