#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <linked_list.h>
#include <print_utility.h>

static void* _get_data_copy(struct linked_list* self, void* data) {
    void* data_copy = malloc(self->void_type->size);
    memcpy(data_copy, data, self->void_type->size);
    return data_copy;
}

struct linked_list get_linked_list(struct void_type* void_type, struct node* start) {
    struct linked_list ll = {
        ll.void_type = void_type,
        ll.start = start,
        ll.print_list = print_list,
        ll.list_add = list_add,
        ll.list_find = list_find,
        ll.node_delete = node_delete
    };
    return ll;
}

void list_add(struct linked_list* self, void* new_data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = _get_data_copy(self, new_data);
    new_node->prev = NULL;
    if (NULL != self->start) {
        self->start->prev = new_node;
    }
    new_node->next = self->start;
    self->start = new_node;
}

struct node* list_find(struct linked_list* self, void* data) {
    void* data_copy = _get_data_copy(self, data);
    struct node* p = self->start;
    while (NULL != p) {
        if (self->void_type->compare(self->void_type, p->data, data_copy)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void node_delete(struct node* node) {
    if (NULL != node->prev) {
        node->prev->next = node->next;
    }
    if (NULL != node->next) {
        node->next->prev = node->prev;
    }
    free(node);
}

// struct node list_remove(struct node *list, void *data, size_t data_size) {
//     struct node *p = list;
//     while (p != NULL) {
//         if (p->next->data == data) {
//             struct node *old = p->next;
//             if (p->next->next != NULL) {
//                 p->next = p->next->next;
//             }
//             else {
//                 p->next = NULL;
//             }
//         }
//         p = p->next;
//     }
//     return *list;
// }

void print_list(struct linked_list *self) {
    struct node *p = self->start;
    while (NULL != p) {
        self->void_type->print(self->void_type, p->data);
        p = p->next;
    }
}