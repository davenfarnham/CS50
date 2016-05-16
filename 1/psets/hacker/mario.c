/*
 * Print out a two sided pyramid. So, if the value is 4, the output should be:
 *
 *                                   # #
 *                                  ## ##
 *                                 ### ###
 *                                #### ####
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <cs50.h>

void print_pyramid(int x);

int main(void)
{
    int height = 0;

    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while(height < 0 || height > 23);

    print_pyramid(height);
}

void print_pyramid(int x)
{
    for(int i = x; i > 0 ; i--)
    {
        for(int rows = i - 1; rows > 0 ; rows--)
            printf(" ");
        for(int columns = i - 1; columns < x; columns++)
            printf("#");
        printf("  ");
        for(int columns = i - 1; columns < x; columns++)
            printf("#");

        printf("\n");
    }
}
