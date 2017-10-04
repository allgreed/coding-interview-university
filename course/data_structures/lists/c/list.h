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
bool List_empty(List* list);
int List_at(List* list, int index);

void List_insert(List* list, int index, int value);
void List_erase(List* list, int index);

#endif  // PROJECT_LINKED_LIST_H
