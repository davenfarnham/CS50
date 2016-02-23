/*
 * something that might be useful before attempting crypto
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>

// macro (i.e. a defined value)
#define MAX 26

int main(void)
{
    char alpha[26] = "abcdefghijklmnopqrstuvwxyz";

    printf("%c\n", alpha[0%MAX]);
    printf("%c\n", alpha[5%MAX]);
    printf("%c\n", alpha[25%MAX]);
    printf("%c\n", alpha[26%MAX]);
    printf("%c\n", alpha[100%MAX]);

    #undef MAX
    #define MAX 25

    printf("%c\n", alpha[100%MAX]); // should be different now
}
