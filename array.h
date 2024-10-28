#ifndef ARRAY_H
#define ARRAY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define add(array, value) da_add((DynamicArray*)array, &value) 
#define get(array, index) da_get((DynamicArray*)array, index) 
#define get_safe(array, index) da_get_safe((DynamicArray*)array, index) 
#define set(array, index, value) da_set((DynamicArray*)array, index, &value)
#define set_safe(array, index, value) da_set_safe((DynamicArray*)array, index, &value)
#define remove_at(array, index) da_remove_at((DynamicArray*)array, index)
#define remove_first(array, value) da_remove_first((DynamicArray*)array, &value)

typedef enum ArrayType {
    Other,
    Int16
} ArrayType;

typedef struct IntDynamicArray {
    ArrayType array_type;
    size_t type_size;
    int count;
    int* array;
} IntDynamicArray; 

typedef struct DynamicArray {
    ArrayType array_type;
    size_t type_size;
    int count;
    void* array;
} DynamicArray;

void da_add(DynamicArray* array, const void* value_ptr);
void* da_get(DynamicArray* array, int index);
void* da_get_safe(DynamicArray* array, int index);
void da_set(DynamicArray* array, int index, const void* value_ptr);
void da_set_safe(DynamicArray* array, int index, const void* value_ptr);
void da_remove_at(DynamicArray* array, int index);
int da_remove_first(DynamicArray* array, void* value_ptr);
DynamicArray* init_array(ArrayType array_type, size_t type_size, int count);
#endif
