#include <stdio.h>
#include "array.h"

void print_int_array(IntDynamicArray* array) {
    printf("Array of size %d with type of size %ld should occupy %ld bytes.\n", array->count, array->type_size, array->count * array->type_size);
    printf("Values:\n");
    for (int i = 0; i < array->count; i++) {
        printf("\tValue %d: %d\n", i, *(array->array + i));
        printf("\tPointer %d: %p\n", i, (array->array + i));
    }
}

int main (void) {
    IntDynamicArray* intArray = (IntDynamicArray*)init_array(4, 0);
    for(int i = 0; i < 10; i++) {
        add(intArray, i);
    }
    print_int_array(intArray);
    return 0;
}
