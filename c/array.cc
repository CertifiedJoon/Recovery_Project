#include "array.h"
#include <stdbool.h>
array *new_array(int capacity){
  int AdjustedCapacity = adjust_capacity(capacity);
  
  array *arr = (array *) malloc (sizeof(array));
  CheckNull(arr);
  arr->size = 0;
  arr->capacity = AdjustedCapacity;
  arr->data = (int*) malloc (sizeof(int) * AdjustedCapacity);
  CheckNull(arr->data);
  
  return arr;
}

void CheckNull(void *p) {
  if (p == NULL){
    printf("Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }
}

void array_CheckBound(array *arr, int index){
  if (index + 1 > arr->size || index < 0){
    printf("index out of bound\n");
    exit(EXIT_FAILURE);
  }
}

int array_isempty(array *arr) {
  if (arr->size == 0)
     return 1;
  return 0;
}

int array_size(array *arr) {return arr->size;}

int array_capacity(array *arr) {return arr->size;}

int array_at(array *arr, int index) {
  array_CheckBound(arr, index);
  return *(arr->data + index);
}

void array_resize(array *arr){
  if (arr->size >= arr->capacity)
    array_upsize(arr);
  
  if (arr->size <= arr->capacity / ShrinkFactor)
    array_downsize(arr);
}

void array_upsize(array *arr){
  int OldCap = arr->capacity;
  int NewCap = adjust_capacity(OldCap);
  
  array *new_arr = (array *) realloc (arr->data, sizeof(int) * NewCap);
  CheckNull(new_arr);
  
  arr->data = new_arr->data;
  arr->capacity = NewCap;
}

void array_downsize(array *arr){
  int OldCap = arr->capacity;
  int NewCap = OldCap / ShrinkFactor;
  array *new_arr = (array *) realloc (arr-.data, sizeof(int) * NewCap);
  CheckNull(new_arr);
  
  arr->data = new_arr->data;
  arr->capacity = NewCap;
}

int adjust_capacity(int capacity) {
  const int MinInitialCapacity = 1;
  int AdjustedCapacity = MinInitialCapacity;
  
  if (capacity < MinInitialCapaciy) { exit (EXIT_FAILURE); }
  
  while (AdjustedCapacity / GrowthFactor < capacity){
    AdjustedCapacity *= cjGrowthFactor;
  }
  
  return AdjustedCapacity;
}

void array_push(array *arr, int val){
  array_resize(arr);
  *(arr->data + arr->size) = val;
  ++(arr->size);
}

void array_insert(array *arr, int index, int val){
  array_CheckBound(arr, index);
  array_resize(arr);
  
  memmove(arr->data + index + 1, arr->data + index, sizeof(int) * (arr->size - index));
  *(arr->data + index) = val;
  ++(arr->size);
}

void array_delete(array *arr, int index){
  array_CheckBound(arr, index);
  memmove(arr->data + index, arr->data + index + 1, sizeof(int) * (arr->size - index - 1));
  (arr->size)--;
  
  array_resize(arr);
}

int array_pop(array *arr){
  CheckNull(arr);
  array_resize(arr);
  
  int popped = (arr->data + arr->size - 1);
  (arr->size)--;
  
  return popped;
}

void array_destory(array *arr){
  free(arr->data);
  free(arr);
}

int array_find(array *arr, int val){
  for(int *it = arr->data; it != arr->data + arr->size; it++){
    if (*it == val)
      return 1;
  }
  return 0;
}
