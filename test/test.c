#include "test.h"
#include "../array.c"
#include "tester.c"
#include "array_void_test.c"
#include "array_test.c"

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

  describe("reduce_void()");
  it("should add numbers with initial value", assert_reduce_void_sum_with_initial());
  it("should add numbers", assert_reduce_void_sum());

  printf("\nTEST END..............");
  return 0;
}