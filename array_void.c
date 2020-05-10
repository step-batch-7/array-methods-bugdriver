#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_void(int length)
{
  ArrayVoid_ptr array = malloc(sizeof(ArrayVoid));
  if (array != NULL)
  {
    array->array = malloc(sizeof(Object) * length);
    array->length = length;
  }
  return array;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  ArrayVoid_ptr list = create_array_void(src->length);
  int filter_element_count = 0;
  for (int index = 0; index < src->length; index++)
  {
    if ((*predicate)(src->array[index]))
    {
      list->array[filter_element_count] = src->array[index];
      filter_element_count += 1;
    }
  }
  list->array = realloc(list->array, sizeof(Object) * filter_element_count);
  list->length = filter_element_count;
  return list;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr array = create_array_void(src->length);
  for (int index = 0; index < src->length; index++)
  {
    array->array[index] = mapper(src->array[index]);
  }
  return array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  Object reduced_value = init;
  for (int index = 0; index < src->length; index++)
  {
    reduced_value = (*reducer)(reduced_value, src->array[index]);
  }
  return reduced_value;
}

void display_void_array(ArrayVoid_ptr src, DisplayData printer)
{
  printf("[ ");
  for (int index = 0; index < src->length; index++)
  {
    index != 0 && printf(", ");
    (*printer)(src->array[index]);
  }
  printf(" ]");
}