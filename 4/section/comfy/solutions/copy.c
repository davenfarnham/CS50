/*
 *
 * Daven Farnham (2015)
 *
 * Copy a text file.
 *
 */

#include <stdio.h>

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

	char c = fgetc(in);

	while(c != EOF)
	{
		fputc(c, out);
		c = fgetc(in);
	}

	fclose(in);
	fclose(out);
}
