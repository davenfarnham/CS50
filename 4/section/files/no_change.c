#include <stdio.h>

void change(int* i);

int main(void)
{
    // variable i points to 42
    int p = 42;

    // pass pointer to change
    change(&p);

    printf("i is now %i\n", p);
}

void change(int* p)
{
    *p = *p + 8;
}
