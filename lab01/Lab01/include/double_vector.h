#ifndef DOUBLE_VECTOR_H
#define DOUBLE_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/app.h"

typedef double* pvector_t;
typedef double value_t;
typedef long double lvalue_t;

static const double MIN_VALUE = -15.0;
static const double MAX_VALUE =  15.0;

lvalue_t    dot_product(pvector_t vec1, pvector_t vec2, int size);
lvalue_t    MP_dot_product(pvector_t vec1, pvector_t vec2, int size);
bool        generate_vector(pvector_t *vec, PCONFIG config, value_t min, value_t max);
void        print_vector(pvector_t vec, int size);

#endif // DOUBLE_VECTOR_H
