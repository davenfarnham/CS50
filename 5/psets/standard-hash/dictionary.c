/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// nodes to put into hashtable
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;

} node;

// my hashtable of node pointers
node* hashtable[SIZE_TABLE];

// global size varible
int count = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char* lower_case = to_lower((char*) word);

    // index into our hashtable
    int index = hash_function(lower_case);

    node* check = NULL;

    check = hashtable[index];

    while(check != NULL)
    {
        if(strcmp((const char*) check->word, lower_case) == 0)
        {
            free(lower_case);
            return true;
        }
        else
            check = check->next;
    }

    free(lower_case);
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open dictionary
    FILE* fp = fopen(dictionary, "r");

    // check and see if file pointer is NULL, if it is return false
    if(fp == NULL)
        return false;

    // declare buffer
    char buffer[LENGTH + 1];

    while(fscanf(fp, "%s", buffer) == 1)
    {
        node* ptr = malloc(sizeof(node));

        if(strcpy(ptr->word, (const char*) buffer) == NULL)
        {
            free(ptr);
            return false;
        }

        int index = hash_function(ptr->word);

        if(hashtable[index] == NULL)
            hashtable[index] = ptr;
        else
        {
            ptr->next = hashtable[index];
            hashtable[index] = ptr;
        }

        count++;
    }

    fclose(fp);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0; i < SIZE_TABLE; i++)
    {
        node* ptr = hashtable[i];
        if(ptr != NULL)
        {
            node* forward = ptr->next;

            while(forward != NULL)
            {
                free(ptr);

                ptr = forward;
                forward = forward -> next;

            }

            free(ptr);
        }
    }

    return true;
}

/**
 * Bad hash function - return first letter of word
 */
int hash_function(char* s)
{
    if(s[0] >= 'a' && s[0] <= 'z')
        return s[0] - 'a';
    else
        return s[0] - 'A';
}


/**
 * Convert string to lower case
 */
char* to_lower(char* s)
{
    char* tmp = malloc(LENGTH + 1);

    int i = 0;

    while(s[i] != '\0')
    {
        tmp[i] = tolower(s[i]);
        i++;
    }

    tmp[i] = '\0';

    return tmp;
}
