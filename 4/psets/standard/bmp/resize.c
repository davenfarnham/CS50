/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resizes a bitmap, making extensive use of fseek(). General method: if you're
 * resizing a line, read a RGB triple and write it out n times. When you get to the
 * end of the line, fseek() back to the beginning of the line and do it again, a total
 * of n times.
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

#define METADATA 54

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy resize infile outfile\n");
        return 1;
    }

    // remember scaling factor
    int scale = atoi(argv[1]);

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // store old width and height
    LONG oldWidth = bi.biWidth;
    LONG oldHeight = bi.biWidth;

    // determine padding of infile
    int old_padding =  (4 - (oldWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // change BITMAPINFOHEADER biWidth (does not include padding)
    bi.biWidth = bi.biWidth * scale;

    // determine padding for outfile
    int new_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // change BITMAPINFOHEADER biHeight
    bi.biHeight = bi.biHeight * scale;

    // change BITMAPINFOHEADER biSizeImage (includes padding)
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(bi.biHeight); // size of image

    // change BITMAPFILEHEADER bfsize
    bf.bfSize = bi.biSizeImage + METADATA; // size of file

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(oldHeight); i < biHeight; i++)
    {
        // vertical resize
        for(int h = 0; h < scale; h++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < oldWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // resize horizontally
                for(int w = 0; w < scale; w++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // add in padding
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }

            fseek(inptr, -(oldWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
        }

        // skip over padding, if any
        fseek(inptr, (oldWidth * sizeof(RGBTRIPLE)) + old_padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
