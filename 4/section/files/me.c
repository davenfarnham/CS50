#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = GetString();
    int i = GetInt();

    printf("%s's favorite number is %i\n", s, i);
}
