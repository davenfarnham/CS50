#include <stdio.h>
#include <cs50.h>

int main(void)
{
    for(int i = 0; i < 5; i++)
    {
        char* s = GetString();
        printf("You gave me %s\n", s);
    }
}
