#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <void_types.h>

// This linked list is a double-y linked list, with both a next and
// previous pointer. This makes certain types of deletes faster.

struct linked_list {
    struct void_type* void_type;
    struct node* start;
    void (*print_list)(struct linked_list* self);
    void (*list_add)(struct linked_list* self, void *new_data);
    struct node* (*list_find)(struct linked_list* self, void* data);
    void (*node_delete)(struct node* node);
};

struct node {
    void *data;
    struct node *next;
    struct node *prev;
};

struct linked_list get_linked_list(struct void_type*, struct node*);
void list_add(struct linked_list* self, void *new_data);
void print_list(struct linked_list *self);
struct node* list_find(struct linked_list* self, void* data);
void node_delete(struct node* node);

#endif