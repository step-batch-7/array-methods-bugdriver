#include "../array.h"
#include "test.h"

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

test_status assert_filter_empty_list()
{
  Array_ptr list = create_array(0);
  Array_ptr evens = filter(list, &is_even);
  if (evens->length == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_filter_even_numbers()
{
  Array_ptr list = create_array(4);
  list->array[0] = 1;
  list->array[1] = 2;
  list->array[2] = 3;
  list->array[3] = 4;
  Array_ptr evens = filter(list, &is_even);
  if (evens->array[0] == 2 && evens->array[0] == 2 && evens->length == 2)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_map_empty_list()
{
  Array_ptr list = create_array(0);
  Array_ptr squares = map(list, &square);
  if (squares->length == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_map_numbers_with_square()
{
  Array_ptr list = create_array(2);
  list->array[0] = 2;
  list->array[1] = 3;
  Array_ptr squares = map(list, &square);
  if (squares->array[0] == 4 && squares->array[1] == 9 && squares->length == 2)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_reduce_add_numbers_with_initial()
{
  Array_ptr list = create_array(3);
  list->array[0] = 10;
  list->array[1] = 20;
  list->array[2] = 30;
  int sum = reduce(list, 40, &add);
  if (sum == 100)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_reduce_add_numbers()
{
  Array_ptr list = create_array(3);
  list->array[0] = 10;
  list->array[1] = 20;
  list->array[2] = 30;
  int sum = reduce(list, 0, &add);
  if (sum == 60)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_reduce_empty_list_initial()
{
  Array_ptr list = create_array(0);
  int sum = reduce(list, 10, &add);
  if (sum == 10)
  {
    return Pass;
  }
  return Fail;
}
