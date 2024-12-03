#ifndef VOIDTYPES_H
#define VOIDTYPES_H

#include <stdio.h>

struct void_type
{
    size_t size;
    void (*print)(struct void_type* self, void *void_int);
    int (*compare)(struct void_type* self, void* a, void* b);
};

struct void_type get_void_int(void);
void print_void_int(struct void_type* void_type, void* void_int);
int compare_void_int(struct void_type* self, void* a, void* b);

#endif