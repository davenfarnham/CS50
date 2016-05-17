/*
 *
 * Daven Farnham (2015)
 *
 * Copy a text file using fread().
 *
 */

#include <stdio.h>
#define BUFFERSIZE 100
#define ITEMS 1

int main (int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Usage: [src] [dest]\n");
		return 1;
	}

	// read in from the file
	FILE* in = fopen(argv[1], "r");

	if(!in)
	{
		printf("Problem reading in file\n");
		return 2;
	}

	// open file to write out to
	FILE* out = fopen(argv[2], "w");

	char buffer[BUFFERSIZE];
	int num = 0;

	// advance file pointer 476 bytes from beginning of file to skip over comments
	// fseek(in, 15000, SEEK_SET);

	// fread(dest buffer, bytes/item, # of items, src)
	while(1)
	{
		num = fread(buffer, ITEMS, BUFFERSIZE, in);

		if (num < BUFFERSIZE)
		    break;

		fwrite(buffer, BUFFERSIZE, ITEMS, out);
	}

	fwrite(buffer, num, ITEMS, out);

	fclose(in);
	fclose(out);
}
