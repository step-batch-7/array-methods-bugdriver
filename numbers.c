#include <stdio.h>
#include "array.h"

Bool is_even(int number)
{
  return number % 2 == 0;
}

int square(int number)
{
  return number * number;
}

int add(int first_number, int second_number)
{
  return first_number + second_number;
}

int main(void)
{
  Array *list = create_array(7);
  list->array[0] = 1;
  list->array[1] = 2;
  list->array[2] = 3;
  list->array[3] = 4;
  list->array[4] = 8;
  list->array[5] = 6;
  list->array[6] = 7;

  Array *even_list = filter(list, &is_even);

  Array *square_list = map(list, &square);

  int addition = reduce(list, 0, &add);

  display_array(even_list);
  printf("\n");
  display_array(square_list);
  printf("\n");
  printf("reduced value is : %d", addition);
  free_array(even_list);
  free_array(square_list);
  free_array(list);
  return 0;
}