#include <stdio.h>
#include <stdlib.h>

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

int main() {
    double *vec1, *vec2;
    int size;

    scanf("%d", &size);
    printf("SIZE: %d\n", size);
    generate_vector(&vec1, size, -5.0, 5.0);
    generate_vector(&vec2, size, -5.0, 5.0);

    print_vector(vec1, size);
    print_vector(vec2, size);

    long double res = scalar(vec1, vec2, size);

    printf("SCALAR: %Lf\n", res);

    if (vec1) free(vec1);
    if (vec2) free(vec2);

    return 0;
}
