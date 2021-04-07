/**
 * Utils module for baerer common-use methods
 * @license MIT
 * @author Fedor Soklakov <fv.soklakov@gmail.com>
 * @version 2020-04-05
 */

#ifndef UTILS_H_
#define UTILS_H_

/*
 * System headers required by the following declarations
 */
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

/*
 * Application specific headers required by the following declarations
 * (the implementation will import its specific dependencies):
 */
#include "etypes.h"

//Summ methods for simple types
int utils_summ_int(int *array, unsigned int length);
float utils_summ_float(float *array, unsigned int length);
double utils_summ_double(double *array, unsigned int length);

//Summ methods for extended types
int utils_summ_e_int(E_ARR_INT e_array);
int utils_summ_e_float(E_ARR_FLOAT e_array);
#endif //UTILS_H_
