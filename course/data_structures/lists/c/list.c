#include "list.h"

#include <stdio.h>
#include <stdlib.h>

// ****************************
// Utility
// ****************************

// @size [bytes]
void* allocate(int size)
{
    void* retval = malloc(size);

    if (retval == NULL)
    {
        fprintf( stderr, "Failed allocation with malloc\n");
        exit(LIST_EXIT_FAILED_ALLOCATION);
    }
    else
        return retval;
}

// ****************************
// Private
// ****************************

ListNode* ListNode_create(int value)
{
    ListNode* node = allocate(sizeof(ListNode));

    node->value = value;
    node->next = NULL;

    return node;
}

void ListNode_destroy(ListNode* node)
{
    free(node);
}

bool ListNode_is_last(ListNode* node)
{
    return (node->next == NULL);
}

ListNode* ListNode_at_index(List* list, int index)
{
    ListNode* node = list;

    for(int i = -1; i < index ; i++)
    {
        // if(ListNode_is_last(node))
            // blow up

        node = node->next;
    }

    return node;
}

// ****************************
// Create and destroy
// ****************************

List* List_init()
{
    return ListNode_create(1);
}

void List_destroy(List* list)
{
    // recurrence maybe here??????
    // nullify the pointer at the end
}

// ****************************
// Basic operations
// ****************************

void List_insert(List* list, int index, int value)
{
    ListNode* previous = ListNode_at_index(list, --index);
    ListNode* newNode = ListNode_create(value);
    newNode->next = previous->next;
    previous->next = newNode;
}

int List_at(List* list, int index)
{
    return ListNode_at_index(list, index)->value;
}

bool List_empty(List* list)
{
    return (ListNode_is_last(list));
}

void List_erase(List* list, int index)
{
    ListNode* previous = ListNode_at_index(list, --index);
    ListNode* erasedNode = previous->next;
    previous->next = erasedNode->next;
    ListNode_destroy(erasedNode);
}
