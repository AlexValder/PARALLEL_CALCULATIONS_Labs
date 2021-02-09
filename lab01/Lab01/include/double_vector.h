#ifndef DOUBLE_VECTOR_H
#define DOUBLE_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double* pvector_t;
typedef double value_t;
typedef long double lvalue_t;

#define ONE_KIB 1024
#define ONE_MIB 1048576 // 1024*1024
#define ONE_GIB 1073741824 // 1024*1024*1024

static const double MIN_VALUE = -15.0;
static const double MAX_VALUE =  15.0;

lvalue_t    dot_product(pvector_t vec1, pvector_t vec2, int size);
void        generate_vector(pvector_t *vec, int size, value_t min, value_t max);
void        print_vector(pvector_t vec, int size);

#endif // DOUBLE_VECTOR_H
