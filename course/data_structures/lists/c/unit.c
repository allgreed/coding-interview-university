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

// remove test
    // add 2 stuff
    // remove first
    // is at(0) == firstStuff ?

// size test
    // is size 0 ?
    // add 2 items
    // is size 1?
    // remove 1 item
    // is size 1?


// empty test
    // is empty ?
    // add 3 item
    // is not empty?
    // remove 3 item
    // is empty?

int main()
{
    getAndSetTest();

    printf("All tests passed!\n");
    return 0;
}
