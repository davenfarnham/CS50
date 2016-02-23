/*
 * hello.c
 *
 * use a function to print out "hello!" multiple times
 */

#include <stdio.h>

void print_hello(void);

int main(void)
{
    print_hello();
}

void print_hello(void)
{
    for(int i= 0; i < 100; i++)
    {
        printf("hello!\n");
    }
}
