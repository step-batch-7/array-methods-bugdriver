#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

Object create_int_object(int value)
{
  int *number = malloc(sizeof(int));
  *number = value;
  return number;
}

Bool is_even(Object number)
{
  int *value = (int *)number;
  return *value % 2 == 0;
}

void print_int(Object object)
{
  int *value = (int *)object;
  printf("%d", *value);
}

int main(void)
{
  ArrayVoid_ptr src = create_array_void(4);
  src->array[0] = create_int_object(1);
  src->array[1] = create_int_object(2);
  src->array[2] = create_int_object(6);
  src->array[3] = create_int_object(4);

  ArrayVoid_ptr even_list = filter_void(src, &is_even);
  display_void_array(even_list, &print_int);
  return 0;
}