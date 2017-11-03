#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HELPERS
// *****************

void* allocate(size_t bytes)
{
    void* retval = malloc(bytes);

    if (retval == NULL)
    {
        fprintf(stderr, "Failed allocation with malloc\n");
        exit(HASHTABLE_EXIT_FAILED_ALLOCATION);
    }

    return retval;
}

// CONSTRUCTOR, DESTRUCTOR
// *****************

HashTable* HashTable_create()
{
    return HashTable_create_of_size(HASHTABLE_DEFAULT_SIZE);
}

HashTable* HashTable_create_of_size(int desired_capacity)
{
    HashTable* new_hash_table = (HashTable*) allocate(sizeof(HashTable));

    new_hash_table->size = 0;
    new_hash_table->capacity = desired_capacity;
    new_hash_table->data = (HashTable_element*) allocate(desired_capacity * sizeof(HashTable_element));

    for(int i = 0; i < desired_capacity; i++)
        new_hash_table->data[i].state = HASHTABLE_ELEM_EMPTY;

    return new_hash_table;
}

void HashTable_destroy(HashTable* hash_table)
{
    free(hash_table->data);
    free(hash_table);
}

// PRIVATES
// *****************

size_t _compute_probe_hash(char* key, int trial, size_t hash_table_capacity)
{
    // pre-hashing
    unsigned int prehash_digest = 0;
    unsigned int key_length = strlen(key);

    for (int i = 0; i < key_length; i++)
        prehash_digest += (int) key[i];

    // hashing
    size_t hash_digest = prehash_digest % hash_table_capacity;

    // linear probing
    return (hash_digest + trial) % hash_table_capacity;
}

int _find_target_index(HashTable* hash_table, char* key)
{
    for(int trial = 0; trial < hash_table->capacity; trial++)
    {
        size_t target_index = _compute_probe_hash(key, trial, hash_table->capacity);

        if (hash_table->data[target_index].state == HASHTABLE_ELEM_EMPTY ||
            strcmp(hash_table->data[target_index].key, key) == 0)
                return target_index;
    }

    return -1;
}

// FUNCTIONS
// *****************

void HashTable_add(HashTable* hash_table, char* key, HashTable_value_t value)
{
    if(hash_table->size == hash_table->capacity)
    {
        fprintf(stderr, "Insertion attempt on full hash table\n");
        exit(HASHTABLE_EXIT_FULL_INSERTION);
    }

    size_t target_index;

    // this is almost identical with _find_target_index, making it DRY not worth it
    for(int trial = 0; trial < hash_table->capacity; trial++)
    {
        target_index = _compute_probe_hash(key, trial, hash_table->capacity);

        if (hash_table->data[target_index].state != HASHTABLE_ELEM_OCCUPIED ||
            strcmp(hash_table->data[target_index].key, key) == 0)
                break;
    }

    if(hash_table->data[target_index].state != HASHTABLE_ELEM_OCCUPIED)
    {
        strcpy(hash_table->data[target_index].key, key);
        hash_table->size++;
    }

    hash_table->data[target_index].value = value;
    hash_table->data[target_index].state = HASHTABLE_ELEM_OCCUPIED;
}

bool HashTable_exists(HashTable* hash_table, char* key)
{
    if (hash_table->size == 0) return false;

    size_t target_index = _find_target_index(hash_table, key);

    return !(target_index == -1 || hash_table->data[target_index].state != HASHTABLE_ELEM_OCCUPIED);
}

HashTable_value_t HashTable_get(HashTable* hash_table, char* key)
{
    size_t target_index = _find_target_index(hash_table, key);

    if(target_index == -1)
    {
        fprintf(stderr, "Non-existing key dereference attempt\n");
        exit(HASHTABLE_EXIT_UNEXISTANT_KEY_DEREFERENCE);
    }

    return hash_table->data[target_index].value;
}

void HashTable_remove(HashTable* hash_table, char* key)
{
    size_t target_index = _find_target_index(hash_table, key);

    if (target_index != -1)
        hash_table->data[target_index].state = HASHTABLE_ELEM_DELETED;

    hash_table->size--;
}
