#include "vector_manipulations.h"


long double scalar(double *vec1, double *vec2, int size) {
    long double res = 0;
    for (int i = 0; i < size; ++i) {
        res += (long double)(vec1[i] * vec2[i]);
    }
    return res;
}

void generate_vector(double** vec, int size, double min, double max) {
    *vec = (double*)malloc(size * sizeof (double));

    for (int i = 0; i < size; ++i) {
        (*vec)[i] = rand() % (int)max + min;
    }
}

void print_vector(double* vec, int size) {
    for (int i = 0; i < size - 1; ++i) {
        printf("%lf ", vec[i]);
    }
    printf("%lf\n", vec[size - 1]);
}
