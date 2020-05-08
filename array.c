#include <stdlib.h>
#include <stdio.h>
#include "array.h"

Array *create_array(unsigned length)
{
  Array *list = malloc(sizeof(Array));
  if (list != NULL)
  {
    list->array = malloc(sizeof(int) * length);
    list->length = length;
  }
  return list;
}

Array *filter(Array *src, Predicate predicate)
{
  Array *list = create_array(src->length);
  unsigned even_count = 0;
  for (int index = 0; index < src->length; index++)
  {
    if ((*predicate)(src->array[index]))
    {
      list->array[even_count] = src->array[index];
      even_count += 1;
    }
  }
  list->array = realloc(list->array, even_count);
  list->length = even_count;
  return list;
}

Array *map(Array *src, Mapper mapper)
{
  Array *list = create_array(src->length);
  for (int index = 0; index < src->length; index++)
  {
    list->array[index] = (*mapper)(src->array[index]);
  }
  return list;
}

int reduce(Array *src, int init, Reducer reducer)
{
  int reduced_value = init;
  for (int index = 0; index < src->length; index++)
  {
    reduced_value = (*reducer)(reduced_value, src->array[index]);
  }
  return reduced_value;
}

void display_array(Array *list)
{
  printf("[ ");
  for (int index = 0; index < list->length; index++)
  {
    index != 0 && printf(", ");
    printf("%d", list->array[index]);
  }
  printf(" ]");
}

void free_array(Array *list)
{
  free(list->array);
  free(list);
}