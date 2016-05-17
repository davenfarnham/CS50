/*
 *
 * Daven Farnham (Fall 2015)
 *
 * Just messing around with file pointers and fseek().
 *
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
	    printf("Usage [src] [dest]\n");
	    return 1;
	}

	FILE* in = fopen(argv[1], "r");

	if(!in)
	{
	    printf("Unable to open file\n");
	    return 2;
	}

	FILE* out = fopen(argv[2], "w");

	if(!out)
	{
	    printf("Unable to open file\n");
	    return 3;
	}

	int c = fgetc(in);

/*	int count = 1;

	// change everything to 'xxx' using fseek()
	while(c != EOF)
	{
		if(count == 3)
			count = 1;
		else if (c == 'x' || c == 'X')
		{
			// rewind file pointer
			fseek(in, -1, SEEK_CUR);
			count++;
		}

		// place values into output file / read in new char
		fputc(c, out);
		c = fgetc(in);
	}
*/

	// in this case, c effectively acts as the buffer I'm writing out 3 times
	while (c != EOF)
	{
		if(c == 'x' || c == 'X')
		{
			for(int i = 0; i < 2; i++)
				fputc(c, out);
		}

		fputc(c, out);
		c = fgetc(in);
	}

	// close files
	fclose(in);
	fclose(out);
}
