/*
 *
 * Helper file. Comment out word and find if you're only compiling sum.c since it won't
 * have an externally declared word[] array.
 *
 */

// extern char word[];

// sum up the entries of an array
int sum (int* array, int count)
{
  int sum = 0;

  for (int i = 0; i < count; i++)
      sum = sum + array[i];

  return sum;
}

// spell out "Meeseeks"
char* find (char* c1, char* c2, char* c3)
{
        word[0] = c3[0];
        word[1] = c1[3];
        word[2] = c1[3];
        word[3] = c1[2];
        word[4] = c1[3];
        word[5] = c1[3];
        word[6] = c2[3];
        word[7] = c1[2];

        // null terminator
        word [8] = '\0';

        return word;
}

