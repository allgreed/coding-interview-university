#ifndef PROJECT_LINKED_LIST_H
#define PROJECT_LINKED_LIST_H

#include <stdbool.h>

extern const int LIST_EXIT_FAILED_ALLOCATION;
extern const int LIST_EXIT_OUT_OF_BOUNDS;
extern const int LIST_EXIT_NEGATIVE_INDEX;

typedef struct ListNode
{
    int value;
    struct ListNode* next;
} ListNode;

extern ListNode* const LIST_NULLPTR;

// To prevent leaking implementation details 
typedef ListNode List;

// Create and destroy
List* List_init();
void List_destroy(List* list);

// Basic operations
bool List_empty(List* list);
int List_at(List* list, int index);
int List_size(List* list);

void List_insert(List* list, int index, int value);
void List_erase(List* list, int index);

// Derived

void List_push_front(List* list, int value);
int List_pop_front(List* list);
void List_push_back(List* list, int value);
int List_pop_back(List* list);

int List_back(List* list);
int List_front(List* list);
int List_value_n_from_end(List* list, int reverseIndex);

// Advanced
void List_reverse(List* list);
void List_remove_value(List* list, int value);

#endif  // PROJECT_LINKED_LIST_H
