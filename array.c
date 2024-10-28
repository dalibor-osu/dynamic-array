#include "array.h"

DynamicArray* init_array(ArrayType array_type, size_t type_size, int count) {
    DynamicArray* array = (DynamicArray*) malloc(sizeof(DynamicArray));
    array->type_size = type_size;
    array->array_type = array_type;
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
    void* newArray = (void*) malloc(array->type_size * (array->count + 1));

    size_t bytesToCopy = array->count * array->type_size;
    void* addressOfNewElement = newArray + bytesToCopy;

    memcpy(newArray, array->array, bytesToCopy);
    memcpy(addressOfNewElement, value_ptr, array->type_size);

    free(array->array);

    array->array = newArray;
    array->count++;
}

void* da_get(DynamicArray* array, int index) {
    return (array->array + (array->type_size * index));
}

void* da_get_safe(DynamicArray* array, int index) {
    if (index < 0 || index >= array->count) {
        fprintf(stderr, "Invalid index %d\n", index);
        return NULL;
    }
    return (array->array + (array->type_size * index));
}

void da_set(DynamicArray* array, int index, const void* value_ptr) {
    memcpy(array->array + (array->type_size * index), value_ptr, array->type_size);
}

void da_set_safe(DynamicArray* array, int index, const void* value_ptr) {
    if (index < 0 || index >= array->count) {
        fprintf(stderr, "Invalid index %d\n", index);
        return;
    }
    memcpy(array->array + (array->type_size * index), value_ptr, array->type_size);
}

void da_remove_at(DynamicArray* array, int index) {
    void* newArray = (void*) malloc(array->type_size * (array->count - 1));
    memcpy(newArray, array->array, array->type_size * index);
    memcpy(newArray + (array->type_size * index), array->array + (array->type_size * (index + 1)), (array->count - index) * array->type_size);

    free(array->array);

    array->array = newArray;
    array->count--;
}

int da_remove_first(DynamicArray* array, void* value_ptr) {
    for (int i = 0; i < array->count; i++) {
        if (memcmp(array->array + (array->type_size * i), value_ptr, array->type_size) == 0) {
            da_remove_at(array, i);
            return 1;
        }
    }

    return 0;
}
