#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void* callocate(size_t count, size_t bytes)
{
    void* retval = calloc(count,bytes);

    if (retval == NULL)
    {
        fprintf(stderr, "Failed allocation with calloc\n");
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
    HashTable* new_hash_table = allocate(sizeof(HashTable));

    new_hash_table->size = 0;
    new_hash_table->capacity = desired_capacity;
    new_hash_table->data = callocate(desired_capacity, sizeof(HashTable_element));
    // since HASHTABLE_ELEM_EMPTY == 0, there is no need to set default values

    return new_hash_table;
}

void HashTable_destroy(HashTable* hash_table)
{
    free(hash_table->data);
    free(hash_table);
}

// PRIVATES
// *****************

static size_t _compute_initial_hash(char* key, size_t hash_table_capacity)
{
    // via https://courses.csail.mit.edu/6.006/spring11/rec/rec05.pdf
    // formula is: (sqrt(5.0) - 1) / 2
    static const double A = 0.6180339887498948;

    // pre-hashing
    unsigned int prehash_digest = 0;
    unsigned int key_length = strlen(key);

    for (int i = 0; i < key_length; i++)
        prehash_digest += (int) key[i];

    // hashing
    size_t hash_digest = floor(hash_table_capacity * (prehash_digest * A));

    return hash_digest;
}

static size_t _compute_probe_hash(size_t hash_digest, int trial, size_t hash_table_capacity)
{
    // linear probing
    return (hash_digest + trial) % hash_table_capacity;
}

static HashTable_locator _find_target_locator(HashTable* hash_table, char* key, bool is_insertion)
{
    size_t hash = _compute_initial_hash(key, hash_table->capacity);
    size_t trial = 0;
    size_t target_index = _compute_probe_hash(hash, trial, hash_table->capacity);

    while(trial < hash_table->capacity 
        && !(hash_table->data[target_index].state == HASHTABLE_ELEM_EMPTY
            || (is_insertion && (hash_table->data[target_index].state != HASHTABLE_ELEM_OCCUPIED))
            || (strcmp(hash_table->data[target_index].key, key) == 0)))
    {
        target_index = _compute_probe_hash(hash, trial, hash_table->capacity);
        trial++;
    }

    HashTable_locator retval;
    retval.to_index = target_index;
    retval.is_valid = !(trial == hash_table->capacity);
    return retval;
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

    size_t target_index = _find_target_locator(hash_table, key, true).to_index;

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

    HashTable_locator target_locator = _find_target_locator(hash_table, key, false);

    return target_locator.is_valid && hash_table->data[target_locator.to_index].state == HASHTABLE_ELEM_OCCUPIED;
}

HashTable_value_t HashTable_get(HashTable* hash_table, char* key)
{
    HashTable_locator target_locator = _find_target_locator(hash_table, key, false);

    if(!target_locator.is_valid)
    {
        fprintf(stderr, "Non-existing key dereference attempt\n");
        exit(HASHTABLE_EXIT_UNEXISTANT_KEY_DEREFERENCE);
    }

    return hash_table->data[target_locator.to_index].value;
}

void HashTable_remove(HashTable* hash_table, char* key)
{
    HashTable_locator target_locator = _find_target_locator(hash_table, key, false);

    if (target_locator.is_valid)
    {
        hash_table->data[target_locator.to_index].state = HASHTABLE_ELEM_DELETED;
        hash_table->size--;
    }
}
