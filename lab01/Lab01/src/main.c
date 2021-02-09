#include "../include/app.h"
#include "../include/double_vector.h"
#include <time.h>

const static long long SIZE = ONE_GIB / sizeof(double) * 4; // in 1KB * in 1MB * in 1GB / sizeof(double)

int main (int argc, char** argv)
{
    clock_t begin, end;
    pvector_t vec1, vec2;
    lvalue_t res;
    int size;

    if (argc >= 2)
    {
        size = atoi(argv[1]);
    }
    else
    {
        size = SIZE;
    }

    {
        long long size_bytes = size * sizeof(value_t),
                size_kib = size_bytes / 1024,
                size_mib = size_kib / 1024;
        printf("SIZE: %Ld byte(s) (%Ld KiB, %Ld MiB)\n", size_bytes, size_kib, size_mib);
    }

    begin = clock();
    generate_vector(&vec1, size, MIN_VALUE, MAX_VALUE);
    generate_vector(&vec2, size, MIN_VALUE, MAX_VALUE);
    end = clock();

    printf("Spent time generating 2 vectors: %lf s\n", (double)(end - begin)/CLOCKS_PER_SEC);

    begin = clock();
    res = dot_product(vec1, vec2, size);
    end = clock();

    printf("Spent time calculating dot product: %lf s\n", (double)(end - begin)/CLOCKS_PER_SEC);
    printf("SCALAR: %Lf\n", res);

    free(vec1);
    free(vec2);

    return 0;
}
