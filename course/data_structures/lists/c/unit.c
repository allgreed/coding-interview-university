#include "list.h"

#include <stdio.h>
#include <assert.h>


void getAndSetTest()
{
    List* list = List_init();

    List_insert(list, 0, 777);
    assert(List_at(list, 0) == 777);

    List_insert(list, 1, 69);
    assert(List_at(list, 1) == 69);

    List_insert(list, 0, -1000000);
    assert(List_at(list, 0) == -1000000);

    List_insert(list, 2, 0);
    assert(List_at(list, 2) == 0);

    List_destroy(list);
}

void eraseTest()
{
    List* list = List_init();

    List_insert(list, 0, 123456);
    List_insert(list, 0, -123456);

    List_erase(list, 0);

    assert(List_at(list, 0) == 123456);

    List_destroy(list);
}

void emptyTest()
{
    List* list = List_init();

    assert(List_empty(list));

    List_insert(list, 0, 498);
    List_insert(list, 0, 0);
    List_insert(list, 0, -49450);

    assert(!List_empty(list));

    List_erase(list, 0);
    List_erase(list, 0);
    List_erase(list, 0);

    assert(List_empty(list));

    List_destroy(list);
}

void frontPushPopTest()
{
    List* list = List_init();

    List_push_front(list, 123);
    List_push_front(list, -123);

    assert(List_at(list, 0) == -123);
    assert(List_at(list, 1) == 123);

    int tmp = List_pop_front(list);
    assert(tmp == -123);

    tmp = List_pop_front(list);
    assert(tmp == 123);

    assert(List_empty(list));

    List_destroy(list);
}

void sizeTest()
{
    List* list = List_init();

    assert(List_size(list) == 0);

    List_push_front(list, 111);
    List_push_front(list, 222);

    assert(List_size(list) == 2);

    List_pop_front(list);

    assert(List_size(list) == 1);

    List_destroy(list);
}

void backPushPopTest()
{
    List* list = List_init();

    List_push_back(list, 456);
    List_push_back(list, -654);

    assert(List_at(list, 0) == 456);
    assert(List_at(list, 1) == -654);

    int tmp = List_pop_back(list);
    assert(tmp == -654);

    tmp = List_pop_back(list);
    assert(tmp == 456);

    assert(List_empty(list));

    List_destroy(list);
}

int main()
{
    getAndSetTest();
    eraseTest();
    emptyTest();
    sizeTest();

    frontPushPopTest();
    backPushPopTest();

    printf("All tests passed!\n");
    return 0;
}
