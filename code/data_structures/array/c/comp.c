#include "vector.h"

#include <stdio.h>
#include <time.h>
// #include <assert.h>

const int INITIAL_SAMPLE = 1000;
const int MEDIAN_SAMPLE = 100000;
const int FINAL_SAMPLE = 10000000;

void pushTest()
{
    const int CASE_FACTOR = 1;

    printf("Starting pushTest():\n");

    clock_t start[3], end[3];
    Vector* vector;

    vector = Vector_init_default();

    start[0] = clock();

    for(int i=0; i < INITIAL_SAMPLE / CASE_FACTOR; i++)
        Vector_push(vector, i);

    end[0] = clock();

    Vector_destroy(vector);
    vector = Vector_init_default();

    start[1] = clock();


    for(int i=0; i < MEDIAN_SAMPLE / CASE_FACTOR; i++)
        Vector_push(vector, i);

    end[1] = clock();

    Vector_destroy(vector);
    vector = Vector_init_default();

    start[2] = clock();

    for(int i=0; i < FINAL_SAMPLE / CASE_FACTOR; i++)
        Vector_push(vector, i);

    end[2] = clock();

    Vector_destroy(vector);

    printf("%lf - clocks for basic pushes per push\n", ((double)(end[0] - start[0])) / INITIAL_SAMPLE);
    printf("%lf - clocks for *100 pushes per push\n", (double)(end[1] - start[1]) / MEDIAN_SAMPLE);
    printf("%lf - clocks for *10k pushes per push\n", (double)(end[2] - start[2]) / FINAL_SAMPLE);
}

void prependTest()
{
    const int CASE_FACTOR = 250;

    printf("Starting prependTest():\n");

    clock_t start[3], end[3];
    Vector* vector;

    vector = Vector_init_default();

    start[0] = clock();

    for(int i=0; i < INITIAL_SAMPLE / CASE_FACTOR; i++)
        Vector_prepend(vector, i);

    end[0] = clock();

    Vector_destroy(vector);
    vector = Vector_init_default();

    start[1] = clock();


    for(int i=0; i < MEDIAN_SAMPLE / CASE_FACTOR; i++)
        Vector_prepend(vector, i);

    end[1] = clock();

    Vector_destroy(vector);
    vector = Vector_init_default();

    start[2] = clock();

    for(int i=0; i < FINAL_SAMPLE / CASE_FACTOR; i++)
        Vector_prepend(vector, i);

    end[2] = clock();

    Vector_destroy(vector);

    printf("%lf - clocks for basic prepends per prepend\n", ((double)(end[0] - start[0])) / INITIAL_SAMPLE);
    printf("%lf - clocks for *100 prepends per prepend\n", (double)(end[1] - start[1]) / MEDIAN_SAMPLE);
    printf("%lf - clocks for *10k prepends per prepend\n", (double)(end[2] - start[2]) / FINAL_SAMPLE);
}

void removeTest()
{
    const int CASE_FACTOR = 100;

    printf("Starting removeTest():\n");

    clock_t start[3], end[3];
    Vector* vector;

    vector = Vector_init_default();
    for(int i=0; i < INITIAL_SAMPLE / CASE_FACTOR; i++)
        Vector_push(vector, 7);

    start[0] = clock();

    Vector_remove(vector, 7);

    end[0] = clock();

    Vector_destroy(vector);
    vector = Vector_init_default();
    for(int i=0; i < MEDIAN_SAMPLE / CASE_FACTOR; i++)
        Vector_push(vector, 2);

    start[1] = clock();

    Vector_remove(vector, 7);

    end[1] = clock();

    Vector_destroy(vector);
    vector = Vector_init_default();
    for(int i=0; i < FINAL_SAMPLE / CASE_FACTOR; i++)
    {
        if(i % 2)
            Vector_push(vector, 2);
        else
            Vector_push(vector, 7);
    }

    start[2] = clock();

    Vector_remove(vector, 7);

    end[2] = clock();

    Vector_destroy(vector);

    printf("%lf - clocks for basic remove\n", ((double)(end[0] - start[0])));
    printf("%lf - clocks for *100 remove\n", (double)(end[1] - start[1]));
    printf("%lf - clocks for *10k remove\n", (double)(end[2] - start[2]));
}

int main()
{
    printf("CLOCKS_PER_SEC: %ld\n", CLOCKS_PER_SEC);

    pushTest();
    prependTest();
    removeTest();

    return 0;
}
