/*
 * copy.c: copy a text file from argv[1] to argv[2]. Check equality by then running the linux
 * command 'diff'
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    // make sure program has enough command line arguments
    if(argc != 3)
        return 1;

    // open input file
    FILE* in = fopen(argv[1], "r");

    // can't open file, so bounce
    if(in == NULL)
        return 2;

    // open output file
    FILE* out = fopen(argv[2], "w");

    // can't open file, so bounce
    if(out == NULL)
        return 3;

    // get the first character out of the input file
    int c = fgetc(in);

    // loop until you reach the end of the input file
    while(c != EOF)
    {
        // write out character
        fputc(c, out);

        // get the next character
        c = fgetc(in);
    }

    // close files
    fclose(in);
    fclose(out);
}
