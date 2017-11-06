#include "hash_table.h"

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

static const size_t initial_sample_size = 10;

void complexity_test_add(int case_factor)
{

    size_t sample_size = initial_sample_size * case_factor;
    char key[255];

    int table_size = 2 * sample_size;

    HashTable* hash_table = HashTable_create_of_size(table_size);

    for(int i = 0; i < sample_size; i++)
    {
        // generate key
        sprintf(key, "%d", i);
        while(strlen(key) < 10)
        {
            char randomchar = '\0';
            while(randomchar == '\0' || (randomchar >= '0' && randomchar <= '9')) randomchar = rand() % 128;

            sprintf(key, "%s%c", key , randomchar);
        }

        clock_t start, end;

        start = clock();
        HashTable_add(hash_table, key ,i);
        end = clock();

         printf("Operation %d clocks is %ld\n", i, (end - start));
    } 

    int cluster_counter = 0;

    for(int i = 0; i < table_size; i++)
    {
        if(hash_table->data[i].state == HASHTABLE_ELEM_OCCUPIED)
            cluster_counter++;
        else
        {
            if (cluster_counter > sample_size / 1000)
                printf("Cluster allert - cluster detected of size %d\n", cluster_counter);

            cluster_counter = 0;
        }
    }

    if(cluster_counter > 0)
    {
        if (cluster_counter > sample_size / 1000)
            printf("Cluster allert - cluster detected of size %d\n", cluster_counter);

        cluster_counter = 0;
    }

    printf("per addition for x%d - %lu samples\n", case_factor, sample_size);

    HashTable_destroy(hash_table);
}

int main()
{
    static const int multiplier = 10;

    complexity_test_add(1);
    complexity_test_add(multiplier);
    complexity_test_add(multiplier * multiplier);
    complexity_test_add(multiplier * multiplier * multiplier);
    complexity_test_add(multiplier * multiplier * multiplier * multiplier);
    // complexity_test_add(multiplier * multiplier * multiplier * multiplier * multiplier);
    // complexity_test_add(multiplier * multiplier * multiplier * multiplier * multiplier * multiplier);

    return 0;
}