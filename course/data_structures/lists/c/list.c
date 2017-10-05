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
        fprintf(stderr, "Failed allocation with malloc\n");
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

    // negative index check

    ListNode* node = list;

    for(int i = -1; i < index ; i++)
    {
        if(ListNode_is_last(node))
        {
            fprintf(stderr, "Out of range access attempt\n");
            exit(LIST_EXIT_OUT_OF_BOUNDS);
        }

        node = node->next;
    }

    return node;
}

int List_endIndex(List* list)
{
    return List_size(list) - 1;
}

// ****************************
// Create and destroy
// ****************************

List* List_init()
{
    List* list = allocate(sizeof(List));

    list->next = NULL;

    return list;
}

void List_destroy(List* list)
{
    ListNode* next;
    ListNode* this = list;

    while(!ListNode_is_last(this))
    {
        next = this->next;
        ListNode_destroy(this);
        this = next;
    }
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

int List_size(List* list)
{
    int size = 0;
    ListNode* node = list;

    while(!ListNode_is_last(node))
    {
        node = node->next;
        size++;
    }

    return size;
}

// ****************************
// Derived operations
// ****************************

void List_push_front(List* list, int value)
{
    List_insert(list, 0, value);
}

int List_pop_front(List* list)
{
    int retval = List_at(list, 0);
    List_erase(list, 0);
    return retval;
}

void List_push_back(List* list, int value)
{
    List_insert(list, List_endIndex(list) + 1, value);
}

int List_pop_back(List* list)
{
    int endIndex = List_endIndex(list);

    int retval = List_at(list, endIndex);
    List_erase(list, endIndex);
    return retval;
}

int List_back(List* list)
{
    return List_at(list, List_endIndex(list));
}

int List_front(List* list)
{
    return List_at(list, 0);
}

int List_value_n_from_end(List* list, int reverseIndex)
{
    int index = List_endIndex(list) - reverseIndex;
    return List_at(list, index);
}
