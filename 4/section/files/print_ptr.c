/*
 * print_ptr.c: illustrate printing out pointers
 */

#include <stdio.h>

int main(void)
{
    // declare a normal variable
    int x = 50;

    // declare an int* pointing to x
    int* y = &x;

    // start printing out memory addresses!
/*
 *   printf("x is: %p\n", x);   <---- This won't work! in class I was on the fence about
 *                                    whether it would just print the memory address of x
 *                                    or throw an error, and it turns out it throws an error
 *                                    since x is just 50, which %p recognizes as an invalid
 *                                    memory address.
 */

    // print out the memory address inside y, which should be the same as &x
    printf("y is: %p\n", y);

    // print out where the variable x is located in memory
    printf("&x is: %p\n", &x);

    // print out where the variable y is in memory
    printf("&y is: %p\n", &y);
}
