#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <void_types.h>

struct void_type get_void_int() {
    struct void_type void_type = {
        void_type.size = sizeof(int),
        void_type.print = print_void_int,
        void_type.compare = compare_void_int
    };
    return void_type;
}

void print_void_int(struct void_type* void_type, void* void_int) {
    void *p = malloc(void_type->size);
    memcpy(p, void_int, void_type->size);
    printf("%i ", *((int *)p));
    free(p);
}

int compare_void_int(struct void_type* self, void* a, void* b) {
    if (*((int *)a) == *((int *)b)) {
        return 1;
    }
    return 0;
}