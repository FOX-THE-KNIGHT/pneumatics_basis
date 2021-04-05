//#include "tester.h"

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "utils.h"
#include "etypes.h"

int main()
{
  int arr[5] = {1, 2, 3, 4, 5};

  E_ARR_INT array;

  array.array = arr;
  array.length = 5;

  printf("Length of arr is: %d\n", array.length);
  printf("Summ of arr is: %d\n", utils_summ_int(array.array, array.length));
  printf("Summ of extended array: %d\n", utils_summ_e_int(array));
  
  return 0;
}
