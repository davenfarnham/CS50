/*
 * crack.c First search through /usr/share/dict/words, hopefully finding a match. If no match is
 * found, create all possible permutations of characters <= MAX characters long. You only need to check
 * first 8 characters because that is all crypt() uses when creating a hash code for a user's password.
 *
 * this is, it should be noted, horrible design with so many nested for loops
 *
 * By Daven Farnham (2014)
 */

#define _XOPEN_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <unistd.h>

#define MAX 8

int main(int argc, char* argv[])
{
    char* hash = NULL;

    // check that user provides an encrypted password
    if(argc != 2)
	return 1;
    else
	hash = argv[1];

    // open dictionary
    FILE* fp = fopen("/usr/share/dict/words", "r");

    // check if dictionary could be opened
    if(fp == NULL)
	return 1;
    else
    {
        // choose something big enough not to segfault
	char dictionary_word[120];

        // iterate through dictionary
	while(fscanf(fp, "%s", dictionary_word) != EOF)
	{
	    char x[2];

            // you can do this, and don't need to iterate through all combinations of
	    // the salt, because the first two characters in the hash ARE the salt
            x[0] = hash[0];
            x[1] = hash[1];

  	    string result = crypt((const char*) dictionary_word, (const char* ) x);
            if(!strcmp(result, hash))
            {
	        printf("%s\n", dictionary_word);
	        return 0;
            }
	}
    }

    // possible chars of password
    char* input = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890./'\"";

    // length of input
    int pos = strlen(input);

    // allocate memory for each attempt to create a word
    char attack[MAX] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    // if searching dictionary fails, create all word combinations
    for(int a = 0; a < pos; a++)
    {
        attack[0] = input[a];

        for(int b = 0; b < pos; b++)
        {
            attack[1] = input[b];

            for(int c = 0; c < pos; c++)
            {
                attack[2] = input[c];

                for(int d = 0; d < pos; d++)
                {
                    attack[3] = input[d];

                    for(int e = 0; e < pos; e++)
                    {
                        attack[4] = input[e];

                        for(int f = 0; f < pos; f++)
                        {
                            attack[5] = input[f];

                            for(int g = 0; g < pos; g++)
                            {
                                attack[6] = input[g];

                                for(int h = 0; h < pos; h++)
                                {
                                    attack[7] = input[h];

	                            char x[2];

                                    x[0] = hash[0];
                                    x[1] = hash[1];

  			            string result = crypt((const char*) attack, (const char* ) x);
        	                    if(!strcmp(result, hash))
                                    {
                                        // make char[] printable with %s by adding '\0'
                                        char printable[9];
	                                memcpy(printable, attack, 8);
	                                printable[8] = '\0';
	                                printf("%s\n", printable);
	                                return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
