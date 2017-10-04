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

// size test
    // is size 0 ?
    // add 2 items
    // is size 1?
    // remove 1 item
    // is size 1?


int main()
{
    getAndSetTest();
    eraseTest();
    emptyTest();

    printf("All tests passed!\n");
    return 0;
}
