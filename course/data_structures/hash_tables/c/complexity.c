#include "hash_table.h"

#include <stdio.h>
#include <time.h>
#include <string.h>

static const size_t initial_sample_size = 100;
static const int multiplier = 10;

void complexity_test_add(int case_factor)
{
    int sample_size = initial_sample_size * case_factor;
    clock_t start, end;
    char _tmp[255];

    HashTable* hash_table = HashTable_create_of_size(2 * sample_size);

    char keys[sample_size][255];

    for (int i = 0; i < sample_size; i++)
    {
        sprintf(keys[i], "%d", i);
        while(strlen(keys[i]) < 10)
        {
            sprintf(keys[i], "%s%s", keys[i] , "a");
        }
    }

    start = clock();

    for(int i = 0; i < sample_size; i++)
        HashTable_add(hash_table, keys[i] ,i);

    end = clock();

    HashTable_destroy(hash_table);

    printf("%lf - clocks per addition for x%d\n", ((double)(end - start)) / sample_size, case_factor);
}

int main()
{
    complexity_test_add(1);
    complexity_test_add(10);
    complexity_test_add(100);

    return 0;
}