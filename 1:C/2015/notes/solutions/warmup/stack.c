/*
 * This doesn't work yet — I want to go back from the pointer to sum()
 * to access the arguments passed to it from the main() stack frame.
 */

#include <stdio.h>

int sum (int a, int b);

int main (void)
{
    int a = 1;

    int b = 2;

    sum(a, b);
}

int sum (int a, int b)
{

    printf ("%i\n", *((int*)(&sum + 8)));

    return a + b;
}
