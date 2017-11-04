#include "hash_table.h"

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

static const size_t initial_sample_size = 1000;

char keys[10000000][255];

void complexity_test_add(int case_factor)
{
    size_t sample_size = initial_sample_size * case_factor;
    clock_t start, end;
    char _tmp[255];

    int table_size = 2 * sample_size;

    HashTable* hash_table = HashTable_create_of_size(table_size);

    for (int i = 0; i < sample_size; i++)
    {
        sprintf(keys[i], "%d", i);
        while(strlen(keys[i]) < 10)
        {
            switch(rand() % 3)
            {
                case 0: 
                    sprintf(keys[i], "%s%s", keys[i] , "a");
                    break;
                case 1:
                    sprintf(keys[i], "%s%s", keys[i] , "f");
                    break;
                case 2:
                    sprintf(keys[i], "%s%s", keys[i] , "x");
                    break;
            }
        }
    }

    start = clock();

    for(int i = 0; i < sample_size; i++)
        HashTable_add(hash_table, keys[i] ,i);

    end = clock();

    int cluster_counter = 0, cluster_start;

    for(int i = 0; i < table_size; i++)
    {
        if(hash_table->data[i].state == HASHTABLE_ELEM_OCCUPIED)
        {
            if (cluster_counter == 0)
                cluster_start = i;

            cluster_counter++;
        }
        else
        {
            if (cluster_counter > sample_size / 1000)
            {
                printf("Cluster allert - cluster detected of size %d\n", cluster_counter);
            }

            cluster_counter = 0;
        }
    }


    printf("%lf - clocks per addition for x%d - %lu samples\n",
     ((double)(end - start)) / sample_size,
      case_factor,
      sample_size);

    HashTable_destroy(hash_table);
}

int main()
{
    static const int multiplier = 5;

    complexity_test_add(1);
    complexity_test_add(multiplier);
    complexity_test_add(multiplier * multiplier);

    return 0;
}