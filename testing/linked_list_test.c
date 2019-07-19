#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
    #define NULL 0
#endif

#define PRI_FROM_VOID_POINT_CONVERTION(value, type) ((type*)value)

struct Linked_Node {
    void* value;
    struct Linked_Node *next;
};

typedef struct Linked_List {
    struct Linked_Node *head;
    struct Linked_Node *tail;
    unsigned int size;
} Linked_List;

Linked_List *new_link() {
    Linked_List *out = (Linked_List*) malloc(sizeof(Linked_List));
    out->head = out->tail = NULL;
    out->size = 0;

    return out;
}

struct Linked_Node *new_linked_node(item)
    void* item; // Item to add to node
{
    struct Linked_Node *out = (struct Linked_Node*) malloc(sizeof(struct Linked_Node));
    out->value = item;
    out->next = NULL;

    return out;
}

void linked_insert(list, value)
    Linked_List *list;  // list to act upon
    void *value;          // value to put inside
{
        if(list == NULL) return;

        struct Linked_Node *node = new_linked_node(value);

        if(list->head == NULL) {
            list->head = list->tail = node;
            list->size++;
            return;
        }
        // Fix void* issue
        void *_head = list->head->value;
        void *_tail = list->tail->value;

        list->tail->next = node;
        list->tail = node;
        list->size++;
}

struct Linked_Node *get_linked_node(list, index) 
    Linked_List *list;  // List to be affected
    unsigned int index; // Index of the node to retrieve from the array
{
    struct Linked_Node *node = list->head;
    for(int i = 0; i < index; i++) {
        node = node->next;
    }

    return node;
}

void *linked_get(list, index) 
    Linked_List *list;  // List to be affected
    unsigned int index; // Index of the value to retrieve from the array
{
    if(index > list->size -1 || index < 0) return NULL;
    if(index == 0 && list->size > 0) return list->head->value;
    if(index == list->size-1) return list->tail->value;

    // Debating if doing this more explicitly
    return get_linked_node(list, index)->value;
}

void linked_free(list)
    Linked_List *list;  // List to be affected
{
    if(list == NULL) return;
    if(list->size == 0) free(list);

    struct Linked_Node *node = list->head;
    for(int i = 0; i < list->size; i++) {
        struct Linked_Node *tmp = node->next;
        free(node);
        node = tmp;
    }

    free(list);
}

void linked_delete(list, index)
    Linked_List *list;  // List to be affected
    unsigned int index; // Index to retrieve from the array
{
    if(list == NULL || index > list->size -1 || index < 0) return;

    if(index == 0 && list->head->next != NULL) {
        struct Linked_Node *node = list->head;
        list->head = node->next;
        free(node);
        list->size--;
        return;
    } 

    struct Linked_Node *prev, *current;

    prev = get_linked_node(list, index-1);
    current = prev->next;
    
    if(current->next == NULL) {
        free(current);
        prev->next = NULL;
        list->tail = prev;
        list->size--;
    } else {
        prev->next = current->next;
        free(current);
        list->size--;
    }
}


int main() {
    Linked_List *list = new_link();
    linked_insert(list, 7);
    linked_insert(list, 8);
    linked_insert(list, 10);
    linked_insert(list, 20);
    
    // printf("%d\n", (int*) get_linked_node(list, 3)->value);

    for(int i = 0; i < list->size; i++) {
	    printf("%d\n", (int*) linked_get(list, i));
	}
    linked_free(list);

    return 0;
}

