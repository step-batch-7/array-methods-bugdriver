#include "../array.h"
#include "../array.c"
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
  Array *list = create_array(0);
  Array *evens = filter(list, &is_even);
  if (evens->length == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_filter_even_numbers()
{
  Array *list = create_array(4);
  list->array[0] = 1;
  list->array[1] = 2;
  list->array[2] = 3;
  list->array[3] = 4;
  Array *evens = filter(list, &is_even);
  if (evens->array[0] == 2 && evens->array[0] == 2 && evens->length == 2)
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

  printf("\nTEST END..............");
  return 0;
}