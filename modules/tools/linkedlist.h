#ifndef LINKEDLIST_H
#define LINKEDLIST_H
    struct Linked_Node {
        void* value;
        struct Linked_Node* next;
    };

    typedef struct Linked_List {
        int size;
        struct Linked_Node* head;
        struct Linked_Node* tail;
    } Linked_List;

    Linked_List *new_list();
    struct Linked_Node *new_linked_node(void* item);
    void linked_insert(Linked_List *list, void* item);
    struct Linked_Node *get_linked_node(list, index);
    void *linked_get(Linked_List *list, unsigned int index);
    void linked_delete(Linked_List *list, unsigned int index);
    void linked_free(Linked_List *list);
#endif