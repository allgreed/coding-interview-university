#ifndef PROJECT_HASH_TABLE_H
#define PROJECT_HASH_TABLE_H

#include <stdbool.h>
#include <stddef.h>

// CONSTS
// *****************

static const size_t HASHTABLE_DEFAULT_SIZE = 10;

// poor man's template
typedef int HashTable_value_t;

typedef enum
{
    HASHTABLE_EXIT_OK,
    HASHTABLE_EXIT_FAILED_ALLOCATION,
    HASHTABLE_EXIT_UNEXISTANT_KEY_DEREFERENCE,
    HASHTABLE_EXIT_FULL_INSERTION
} HASHTABLE_EXIT_CODES;

// TYPES
// *****************

typedef struct HashTable_locator
{
    bool is_valid;
    size_t to_index;
} HashTable_locator;


typedef enum
{
    HASHTABLE_ELEM_EMPTY,
    HASHTABLE_ELEM_DELETED,
    HASHTABLE_ELEM_OCCUPIED
} HASHTABLE_ELEM_STATE;

typedef struct HashTable_element
{
    HashTable_value_t value;
    char key[255];
    HASHTABLE_ELEM_STATE state;
} HashTable_element;

typedef struct HashTable
{
    HashTable_element* data;
    size_t capacity;
    size_t size;
} HashTable;

// FUNCTIONS
// *****************

HashTable* HashTable_create();
HashTable* HashTable_create_of_size(int desired_capacity);
void HashTable_destroy(HashTable* hash_table);

void HashTable_add(HashTable* hash_table, char* key, HashTable_value_t value);
bool HashTable_exists(HashTable* hash_table, char* key);
HashTable_value_t HashTable_get(HashTable* hash_table, char* key);
void HashTable_remove(HashTable* hash_table, char* key);

#endif  // PROJECT_HASH_TABLE_H
