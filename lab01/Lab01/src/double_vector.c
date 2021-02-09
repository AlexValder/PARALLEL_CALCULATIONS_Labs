#include "double_vector.h"


lvalue_t dot_product(pvector_t vec1, pvector_t vec2, int size)
{
    lvalue_t res = 0;
    for (int i = 0; i < size; ++i)
    {
        res += (lvalue_t)(vec1[i] * vec2[i]);
    }
    return sqrt(res);
}


void  generate_vector (pvector_t* vec, int size, value_t min, value_t max)
{
    *vec = (pvector_t)malloc(size * sizeof (value_t));

    if (!*vec)
    {
        fprintf(stderr, "Failed to allocate vector of size %d\n", size);
        exit(1);
    }

    for (int i = 0; i < size; ++i)
    {
        (*vec)[i] = (value_t)(rand() % (int)max + min);
    }
}


void print_vector (double* vec, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        fprintf(stdout, "%lf ", vec[i]);
    }
    fprintf(stdout, "%lf\n", vec[size - 1]);
}
