#ifndef ARRAY_H
#define ARRAY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define add(array, value) da_add((DynamicArray*)array, &value) 
#define get(array, index) da_get((DynamicArray*)array, index) 
#define get_safe(array, index) da_get_safe((DynamicArray*)array, index) 

typedef enum ArrayType {
    Other,
    Int32
} ArrayType;

typedef struct IntDynamicArray {
    size_t type_size;
    ArrayType array_type;
    int count;
    int* array;
} IntDynamicArray; 

typedef struct DynamicArray {
    size_t type_size;
    ArrayType array_type;
    int count;
    void* array;
} DynamicArray;

void da_add(DynamicArray* array, const void* value_ptr);
void* da_get(DynamicArray* array, int index);
void* da_get_safe(DynamicArray* array, int index);
DynamicArray* init_array(size_t type_size, int count);
#endif
