#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

DynamicArray* init_array(size_t type_size, int count) {
    DynamicArray* array = (DynamicArray*) malloc(sizeof(DynamicArray));
    array->type_size = type_size;
    array->array_type = Other;
    array->count = count;
    if (count > 0) {
        array->array = (void*) malloc(type_size * count);
    }
    else {
        array->array = NULL;
    }
    return array;
}

void da_add(DynamicArray* array, const void* value_ptr) {
    size_t bytesToAllocate = (array->count + 1) * array->type_size;
    void* newArray = (void*) malloc(bytesToAllocate);

    size_t bytesToCopy = array->count * array->type_size;
    void* addressOfNewElement = newArray + bytesToCopy;

    memcpy(newArray, array->array, bytesToCopy);
    memcpy(addressOfNewElement, value_ptr, array->type_size);

    free(array->array);

    array->array = newArray;
    array->count++;
}

void* da_get(DynamicArray* array, int index) {
    if (index < 0 || index >= array->count) {
        fprintf(stderr, "Invalid index %d", index);
        exit(1);
    }
    return (array->array + (array->type_size * index));
}

void* da_get_safe(DynamicArray* array, int index) {
    if (index < 0 || index >= array->count) {
        fprintf(stderr, "Invalid index %d", index);
        return NULL;
    }
    return (array->array + (array->type_size * index));
}
