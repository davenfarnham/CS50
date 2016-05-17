#include <stdio.h>

void change(int* i);

int main(void)
{
    // variable i points to 42
    int i = 42;

    // pass pointer to change
    change(&i);

    // print it out
    printf("i is now %i\n", i);
}

// change value
void change(int* p)
{
    *p = *p + 8;
}
