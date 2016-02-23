/*
 * A bit redundant, but the size of all datatypes
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Int
    printf("The size of %s is: %d bytes\n", "int", sizeof(int));

    // Float
    printf("The size of %s is: %d bytes\n", "float", sizeof(float));

    // Double
    printf("The size of %s is: %d bytes\n", "double", sizeof(double));

    // Long Long
    printf("The size of %s is: %d bytes\n", "long long", sizeof(long long));

    // Char
    printf("The size of %s is: %d bytes\n", "char", sizeof(char));

    // Short
    printf("The size of %s is: %d bytes\n", "short", sizeof(short));

    // String (char*)
    printf("The size of %s is: %d bytes\n", "string", sizeof(string));

    // Bool
    printf("The size of %s is: %d bytes\n", "bool", sizeof(bool));
}
