#include <stdio.h>

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void print_array(int* array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void insertion_sort(int* array, int length) {
    for (int i = 0; i < length; i++) {
        for (int k = i; k > 0 && array[k-1] > array[k]; k--) {
            swap(&array[k], &array[k-1]);
        }
    }
    print_array(array, length);
}