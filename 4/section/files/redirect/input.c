#include <stdio.h>
#include <cs50.h>

/*
 * Use this program with a redirection command. For example: "./input < number.txt" which outputs 50
 */

int main(void)
{
    int number = GetInt();
    printf("%i\n", number + 1);
}
