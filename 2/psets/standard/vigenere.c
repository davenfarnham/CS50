/*
 * A Vigenere Cipher, whereby you rotate the letters in some string depending on a second string, aka "mask"
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET 26

int main(int argc, char* argv[])
{
	// check that there are two command line arguments
	if(argc != 2)
	{
            printf("Input: cipher\n");
	    return 1;
	}

    	// char*, same as "string"
	char* mask = (argv[1]);

    	// length of mask
	int masklength = strlen(mask);

	for(int i = 0; i < masklength; i++)
	{
	    // if mask isn't alpha, exit
	    if(!isalpha(mask[i]))
            {
                printf("Only letters!\n");
                return 1;
            }
	    // if it is, convert to number between 0 & 26
	    else
	    {
		if(mask[i] >= 'A' && mask[i] <= 'Z')
		    mask[i] = mask[i] - 'A';
		else
		    mask[i] = mask[i] - 'a';
	    }
	}

	// store string into an array of chars
	char* input= GetString();

	for(int i = 0, k = 0; i < strlen(input); i++, k++)
	{
		if(input[i] >= 'A' && input[i] <= 'Z')
		{
			input[i] = input[i] - 'A';
			input[i] = (input[i] + mask[k%masklength]) % ALPHABET;
			input[i] = input[i] + 'A';
		}
		else if(input[i] >= 'a' && input[i] <= 'z')
		{
			input[i] = input[i] - 'a';
			input[i] = (input[i] + mask[k%masklength]) % ALPHABET;
			input[i] = input[i] + 'a';
		}
		else
			k--;
	}

	printf("%s\n", input);
}
