
#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include "array.h"

typedef void *Object;
typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);

typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;
typedef void (*DisplayData)(void *);

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);
ArrayVoid_ptr create_array_void(int length);
void display_void_array(ArrayVoid_ptr src, DisplayData printer);

#endif