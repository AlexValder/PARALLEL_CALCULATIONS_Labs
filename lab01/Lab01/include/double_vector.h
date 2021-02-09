#ifndef DOUBLE_VECTOR_H
#define DOUBLE_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include "../include/app.h"

typedef double* pvector_t;
typedef double value_t;
typedef long double lvalue_t;

static const double MIN_VALUE = -15.0;
static const double MAX_VALUE =  15.0;

lvalue_t    dot_product(PCONFIG config, pvector_t vec1, pvector_t vec2);
lvalue_t    MP_dot_product(PCONFIG config, pvector_t vec1, pvector_t vec2);
bool        generate_vector(pvector_t *vec, PCONFIG config, value_t min, value_t max);
bool        MP_generator_vector(pvector_t *vec, PCONFIG config, value_t min, value_t max);
void        print_vector(pvector_t vec, int size);

#endif // DOUBLE_VECTOR_H
