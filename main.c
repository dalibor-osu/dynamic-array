#include "array.h"

void print_int_array(IntDynamicArray* array) {
    printf("Array of size %d with type of size %ld should occupy %ld bytes.\n", array->count, array->type_size, array->count * array->type_size);
    printf("Values:\n");
    for (int i = 0; i < array->count; i++) {
        printf("\tValue %d: %d\n", i, *(array->array + i));
    }
}

int main (void) {
    IntDynamicArray* intArray = (IntDynamicArray*)init_array(Int16, sizeof(int), 0);
    for(int i = 0; i < 10; i++) {
        add(intArray, i);
    }
    print_int_array(intArray);

    remove_at(intArray, 2);
    print_int_array(intArray);

    int newVal = 10;
    set(intArray, 2, newVal);
    print_int_array(intArray);

    if (remove_first(intArray, newVal) == 1) {
        printf("Removed %d\n", newVal);
    } else {
        printf("Couldn't find %d\n", newVal);
    }
    print_int_array(intArray);

    newVal = 20;
    if (remove_first(intArray, newVal) == 1) {
        printf("Removed %d\n", newVal);
    } else {
        printf("Couldn't find %d\n", newVal);
    }
    print_int_array(intArray);

    return 0;
}
