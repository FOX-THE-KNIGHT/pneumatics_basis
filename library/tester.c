// #include "tester.h"

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct extendedArray_int
{
  int *array;
  int length;
};

void main()
{
  int arr[5] = {1, 2, 3, 4, 5};

  struct extendedArray_int array;

  array.array = arr;
  array.length = 5;

  printf("Length of arr is: %d\n", array.length);
}