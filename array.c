#include <stdlib.h>
#include <stdio.h>
#include "array.h"

Array_ptr create_array(unsigned length)
{
  Array_ptr list = malloc(sizeof(Array));
  if (list != NULL)
  {
    list->array = malloc(sizeof(int) * length);
    list->length = length;
  }
  return list;
}

Array_ptr filter(Array_ptr src, Predicate predicate)
{
  Array_ptr list = create_array(src->length);
  unsigned filter_element_count = 0;
  for (int index = 0; index < src->length; index++)
  {
    if ((*predicate)(src->array[index]))
    {
      list->array[filter_element_count] = src->array[index];
      filter_element_count += 1;
    }
  }
  list->array = realloc(list->array, sizeof(int) * filter_element_count);
  list->length = filter_element_count;
  return list;
}

Array_ptr map(Array_ptr src, Mapper mapper)
{
  Array_ptr list = create_array(src->length);
  for (int index = 0; index < src->length; index++)
  {
    list->array[index] = (*mapper)(src->array[index]);
  }
  return list;
}

int reduce(Array_ptr src, int init, Reducer reducer)
{
  int reduced_value = init;
  for (int index = 0; index < src->length; index++)
  {
    reduced_value = (*reducer)(reduced_value, src->array[index]);
  }
  return reduced_value;
}

void display_array(Array_ptr list)
{
  printf("[ ");
  for (int index = 0; index < list->length; index++)
  {
    index != 0 && printf(", ");
    printf("%d", list->array[index]);
  }
  printf(" ]");
}

void free_array(Array_ptr list)
{
  free(list->array);
  free(list);
}