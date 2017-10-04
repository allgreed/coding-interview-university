#ifndef PROJECT_LINKED_LIST_H
#define PROJECT_LINKED_LIST_H

#include <stdbool.h>

extern const int LIST_EXIT_FAILED_ALLOCATION;

typedef struct
{
    int value;
    struct ListNode* next;
} ListNode;

// To prevent leaking implementation details 
typedef ListNode List;

// Create and destroy
List* List_init();
void List_destroy(List* list);

// Basic operations
void List_insert(List* list, int index, int value);
int List_at(List* list, int index);

#endif  // PROJECT_LINKED_LIST_H
