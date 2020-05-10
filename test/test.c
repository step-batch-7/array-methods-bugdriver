#include "../array.h"
#include "test.h"
#include "../array.c"
#include "tester.c"
#include "array_void_test.c"

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

int main(void)
{
  printf("\nTEST START..............\n\n");

  describe("filter()");
  it("should return empty list when src list is empty", assert_filter_empty_list());
  it("should filter even numbers in list", assert_filter_even_numbers());

  describe("map()");
  it("should return empty list when src list is empty", assert_map_empty_list());
  it("should map numbers with square of numbers in list", assert_map_numbers_with_square());

  describe("reduce()");
  it("should return initial value when src list is empty", assert_reduce_empty_list_initial());
  it("should add numbers with initial value", assert_reduce_add_numbers_with_initial());
  it("should add numbers", assert_reduce_add_numbers());

  describe("filter_void()");
  it("should filter vowels from list of characters", assert_filter_void_vowels());
  it("should filter even numbers in list", assert_filter_void_evens());

  describe("map_void()");
  it("should map characters to lowercase", assert_map_void_lowercase());
  it("should map numbers to increment by 1", assert_map_void_increment_by_1());
  printf("\nTEST END..............");
  return 0;
}