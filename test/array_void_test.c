#include "../array_void.h"
#include "../array_void.c"
#include "test.h"

Object create_int_object(int value)
{
  int *number = malloc(sizeof(int));
  *number = value;
  return number;
}

Object create_char_object(char value)
{
  char *ch = malloc(sizeof(char));
  *ch = value;
  return ch;
}

char cast_to_char(Object object)
{
  return (*(char *)object);
}

int cast_to_int(Object object)
{
  return (*(int *)object);
}

Bool is_vowel(Object object)
{
  char ch = *((char *)object);
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

Bool is_void_even(Object object)
{
  int value = *((int *)object);
  return value % 2 == 0;
}

test_status assert_filter_void_vowels()
{
  ArrayVoid_ptr src = create_array_void(6);
  src->array[0] = create_char_object('a');
  src->array[1] = create_char_object('b');
  src->array[2] = create_char_object('e');
  src->array[3] = create_char_object('c');
  src->array[4] = create_char_object('i');
  src->array[5] = create_char_object('d');
  ArrayVoid_ptr vowels = filter_void(src, &is_vowel);
  if (vowels->length == 3 &&
      cast_to_char(vowels->array[0]) == 'a' &&
      cast_to_char(vowels->array[1]) == 'e' &&
      cast_to_char(vowels->array[2]) == 'i')
  {
    return Pass;
  }
  return Fail;
}

test_status assert_filter_void_evens()
{
  ArrayVoid_ptr src = create_array_void(4);
  src->array[0] = create_int_object(1);
  src->array[1] = create_int_object(2);
  src->array[2] = create_int_object(3);
  src->array[3] = create_int_object(4);
  ArrayVoid_ptr evens = filter_void(src, &is_void_even);
  if (evens->length == 2 &&
      cast_to_int(evens->array[0]) == 2 &&
      cast_to_int(evens->array[1]) == 4)
  {
    return Pass;
  }
  return Fail;
}