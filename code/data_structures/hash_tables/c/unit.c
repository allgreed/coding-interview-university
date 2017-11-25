#include "hash_table.h"

#include <stdio.h>
#include <assert.h>

void createAndDestroy()
{
    HashTable* hash_table = HashTable_create();
    HashTable_destroy(hash_table);
}

void insertAndRetrive()
{
    HashTable* hash_table = HashTable_create();

    // one
    HashTable_add(hash_table, "John", -123);
    assert(HashTable_get(hash_table, "John") == -123);

    // 3 more
    HashTable_add(hash_table, "Jane", -1);
    assert(HashTable_get(hash_table, "John") == -123);
    assert(HashTable_get(hash_table, "Jane") == -1);

    HashTable_add(hash_table, "Magues", 0);
    assert(HashTable_get(hash_table, "John") == -123);
    assert(HashTable_get(hash_table, "Jane") == -1);
    assert(HashTable_get(hash_table, "Magues") == 0);

    HashTable_add(hash_table, "Tyrannosaurus rix", 999999999);
    assert(HashTable_get(hash_table, "John") == -123);
    assert(HashTable_get(hash_table, "Jane") == -1);
    assert(HashTable_get(hash_table, "Magues") == 0);
    assert(HashTable_get(hash_table, "Tyrannosaurus rix") == 999999999);

    // overwrite
    HashTable_add(hash_table, "Tyrannosaurus rix", -8);
    assert(HashTable_get(hash_table, "John") == -123);
    assert(HashTable_get(hash_table, "Jane") == -1);
    assert(HashTable_get(hash_table, "Magues") == 0);
    assert(HashTable_get(hash_table, "Tyrannosaurus rix") == -8);

    // collisions
    HashTable_add(hash_table, "Johnd", 512);
    assert(HashTable_get(hash_table, "John") == -123);
    assert(HashTable_get(hash_table, "Jane") == -1);
    assert(HashTable_get(hash_table, "Magues") == 0);
    assert(HashTable_get(hash_table, "Tyrannosaurus rix") == -8);
    assert(HashTable_get(hash_table, "Johnd") == 512);

    HashTable_destroy(hash_table);
}

void existance()
{
    HashTable* hash_table = HashTable_create();

    HashTable_add(hash_table, "John", -123);
    HashTable_add(hash_table, "Jane", -1);
    HashTable_add(hash_table, "Johnd", 512);

    assert(HashTable_exists(hash_table, "John") == true);
    assert(HashTable_exists(hash_table, "Jane") == true);
    assert(HashTable_exists(hash_table, "Johnd") == true);
    assert(HashTable_exists(hash_table, "Kane") == false);
    assert(HashTable_exists(hash_table, "Main") == false);

    HashTable_destroy(hash_table);
}

void delete()
{
    HashTable* hash_table = HashTable_create();

    HashTable_add(hash_table, "John", -123);
    HashTable_add(hash_table, "Jane", -1);
    HashTable_add(hash_table, "Johnd", 512);

    HashTable_remove(hash_table, "Jane");
    HashTable_remove(hash_table, "John");

    assert(HashTable_exists(hash_table, "Jane") == false);
    assert(HashTable_exists(hash_table, "John") == false);
    assert(HashTable_exists(hash_table, "Johnd") == true);

    HashTable_destroy(hash_table);
}

void deleteThanWriteCheckKey()
{
    HashTable* hash_table = HashTable_create();

    HashTable_add(hash_table, "John", -123);
    HashTable_remove(hash_table, "John");

    HashTable_add(hash_table, "Johnd", 512);

    assert(HashTable_exists(hash_table, "John") == false);
    assert(HashTable_exists(hash_table, "Johnd") == true);
    assert(HashTable_get(hash_table, "Johnd") == 512);

    HashTable_destroy(hash_table);
}

int main()
{
    createAndDestroy();
    insertAndRetrive();
    existance();
    delete();
    deleteThanWriteCheckKey();

    printf("All tests passed!\n");
    return HASHTABLE_EXIT_OK;
}
