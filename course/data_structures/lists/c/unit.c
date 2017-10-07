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

    // Just make sure that the list is in correct order
    assert(List_at(list, 0) == -123456);
    assert(List_at(list, 1) == 123456);

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

void backFrontGetterTest()
{
    List* list = List_init();

    List_push_front(list, 3333);
    List_push_front(list, 2222);
    List_push_front(list, 1111);

    assert(List_back(list) == 3333);
    assert(List_front(list) == 1111);

    List_destroy(list);
}

void List_value_n_from_end_test()
{
    List* list = List_init();

    List_push_front(list, 6);
    List_push_front(list, 5);
    List_push_front(list, 4);
    List_push_front(list, 3);
    List_push_front(list, 2);
    List_push_front(list, 1);

    assert(List_value_n_from_end(list, 2) == 4);
    assert(List_value_n_from_end(list, 1) == 5);
    assert(List_value_n_from_end(list, 0) == 6);

    List_destroy(list);
}

void reverseTest()
{
    List* list = List_init();

    List_push_back(list, 45);
    List_push_back(list, 89);
    List_push_back(list, -48);
    List_push_back(list, 23);
    List_push_back(list, 0);
    List_push_back(list, -8);

    List_reverse(list);

    assert(List_at(list, 0) == -8);
    assert(List_at(list, 1) == 0);
    assert(List_at(list, 2) == 23);
    assert(List_at(list, 3) == -48);
    assert(List_at(list, 4) == 89);
    assert(List_at(list, 5) == 45);

    List_destroy(list);
}

void List_remove_value_test()
{
    List* list = List_init();

    // List_remove_value(list, 1000000);

    List_push_back(list, -600);
    List_push_back(list, 2);
    List_push_back(list, 1000000);

    List_remove_value(list, 1000000);

    assert(List_at(list, 0) == -600);
    assert(List_at(list, 1) == 2);
    assert(List_size(list) == 2);

    List_push_front(list, 5);
    List_remove_value(list, 5);

    assert(List_at(list, 0) == -600);
    assert(List_at(list, 1) == 2);
    assert(List_size(list) == 2);

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

    backFrontGetterTest();
    List_value_n_from_end_test();

    List_remove_value_test();
    reverseTest();

    printf("All tests passed!\n");
    return 0;
}
