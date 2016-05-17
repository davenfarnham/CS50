/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image. This is likely a copy from the standard material,
 * as recover hacker edition == recover standard edition
 */

#include <stdio.h>

#define SIZE 512

int main(int argc, char* argv[])
{
    // open the raw file
    FILE* raw = fopen("card.raw", "r");

    if(raw == NULL)
        return 1;

    // create a buffer
    unsigned char buffer[SIZE];

    // number of jpgs
    int jpg = 0;

    // output file
    FILE* out = NULL;

    while(fread(&buffer, SIZE, 1, raw) == 1)
    {
        // test if it's likely a JPG
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // if out already points to a file, then close it
            if(out != NULL)
                fclose(out);

            // create buffer for title
            char title[7];

            // create a string from int
            sprintf(title, "%.3i.jpg", jpg++);

            // open file
            out = fopen(title, "a");

            if(out == NULL)
                return 2;

            // write to out file
            fwrite(&buffer, SIZE, 1, out);
        }
        else if(out != NULL)
            fwrite(&buffer, SIZE, 1, out);
    }

    // close everything
    if(out != NULL)
        fclose(out);

    fclose(raw);
}
