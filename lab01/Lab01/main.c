#include "vector_manipulations.h"


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

    if (vec1) {
        free(vec1);
    }
    if (vec2) {
        free(vec2);
    }

    return 0;
}
