/*
 * Use this to help debug; will create a hash for a plaintext password, which can then
 * be passed into ./crack [hash]
 *
 * By Daven Farnham (2014)
 */

#define _XOPEN_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <cs50.h>

int main(int argc, char* argv[])
{
    printf("Choose a password <= 8 characters long.\n");

    string s = GetString();

	printf("%s\n", crypt(s, "50"));
}
