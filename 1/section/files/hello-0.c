/*
 * An example of using a function: hello(), and linking in another function, hi(), via a file "helpers.c"
 */

#include <stdio.h>
#include "helpers.h" // basically copy and paste contents of file here

// necessary to put a prototype here
void hello(void);

int main(void)
{
    for(int i = 0; i < 5; i++)
    {
        hello();
    }

    hi();
}

void hello(void)
{
    printf("hello!\n");
}
