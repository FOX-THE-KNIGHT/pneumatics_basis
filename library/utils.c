#include "utils.h"

float _summOf_float(float *array, unsigned int length)
{
  int final = 0;

  for (float *i = &array[0]; i < &array[length - 1]; i++)
    final += *i;

  return final;
}

float _summOf_int(int *array, unsigned int length)
{
  int final = 0;

  for (int *i = &array[0]; i < &array[length - 1]; i++)
    final += *i;

  return final;
}