#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

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

void print_char(Object object)
{
  char *value = (char *)object;
  printf("%c", *value);
}

Object convert_to_lowercase(Object object)
{
  char ch = *((char *)object);
  return create_char_object(ch + 32);
}

int main(void)
{
  ArrayVoid_ptr src = create_array_void(4);
  src->array[0] = create_char_object('A');
  src->array[1] = create_char_object('B');
  src->array[2] = create_char_object('C');
  src->array[3] = create_char_object('D');
  ArrayVoid_ptr lower_case_chars = map_void(src, &convert_to_lowercase);
  display_void_array(lower_case_chars, &print_char);
  return 0;
}