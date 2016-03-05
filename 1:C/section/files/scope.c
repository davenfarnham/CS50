/*
 * a little bit more on scope
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>

// prototypes
void scope1(void);
void scope2(void);

int main(void)
{
    scope1();
    scope2();
}

// scope decided by parantheses
void scope1(void)
{
    {
        int a = 4;
        printf("%d\n", a); // what will this print?
    }

    {
        int a = 5;
        printf("%d\n", a); // what will this print?
    }
}

// scope decided by priority
void scope2(void)
{
    int a = 4;
    (void) a; // have to do this to compile w/out warning "unused variable"

    {
        int a = 0;
        printf("%d\n", a); // what will this print?
    }
}
