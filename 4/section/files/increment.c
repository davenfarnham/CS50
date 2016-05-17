#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // it's gonna get the number from my_number.txt
    string s = GetString();
    int i = atoi(s);

    printf("%i", ++i);
}
