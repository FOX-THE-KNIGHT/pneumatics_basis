#include "utils.h"

int utils_summ_int(int *array, unsigned int length)
{
  int final = 0;

  for (int i = 0; i < length; i++)
    final += *(array + i);

  return final;
}

float utils_summ_float(float *array, unsigned int length)
{
  float final = .0f;

  for (int i = 0; i < length; i++)
    final += *(array + i);

  return final;
}

double utils_summ_double(double *array, unsigned int length)
{
  double final = 0;
  
  for(int i = 0; i < length; i++)
    final += *(array + i);
    
  return final;
}

int utils_summ_e_int(E_ARR_INT e_array)
{
  int final = 0;
  
  for(int i = 0; i < e_array.length; i++)
    final += *(e_array.array + i);
    
  return final;
}

int utils_summ_e_float(E_ARR_FLOAT e_array)
{
  float final = .0f;
  
  for(int i = 0; i < e_array.length; i++)
    final += *(e_array.array + i);
    
  return final;
}
