#include "../include/double_vector.h"
#include <omp.h>


lvalue_t dot_product(PCONFIG config, pvector_t vec1, pvector_t vec2)
{
    lvalue_t res = 0;
    for (int i = 0; i < config->size; ++i)
    {
        res += (lvalue_t)(vec1[i] * vec2[i]);
    }
    return res;
}

lvalue_t MP_dot_product(PCONFIG config, pvector_t vec1, pvector_t vec2)
{
    omp_set_dynamic(0);
    omp_set_num_threads(config->thread_num);
    lvalue_t res = 0;
    int i, size = config->size;

    #pragma omp parallel for shared(vec1, vec2, size) private(i) reduction(+:res)
    for (i = 0; i < size; ++i)
    {
        res += (lvalue_t)(vec1[i] * vec2[i]);
    }
    return res;
}


bool generate_vector(pvector_t* vec, PCONFIG config, value_t min, value_t max)
{
    *vec = (pvector_t)malloc(config->size * sizeof (value_t));

    if (!*vec)
    {
        fprintf(stderr, "Failed to allocate vector of size %Ld\n", config->size);
        return false;
    }

    for (int i = 0; i < config->size; ++i)
    {
        (*vec)[i] = (value_t)(rand() % (int)max + min);
    }

    return true;
}

void print_vector (double* vec, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        fprintf(stdout, "%lf ", vec[i]);
    }
    fprintf(stdout, "%lf\n", vec[size - 1]);
}
