#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* ran_array(int size)
{
    // create an empty array
    int* array = malloc(sizeof(int) * size);

    srand(time(NULL));

    for (int i = 0; i < size; i++)
        *(array + i) = rand();

    return array;
}
