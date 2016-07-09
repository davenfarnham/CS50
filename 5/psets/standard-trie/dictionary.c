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
#include <ctype.h>

#include "dictionary.h"

// struct for trie
typedef struct node
{
    bool is_word;
    struct node* children[27];
} node;

// counter for size
int count = 0;

// prototypes
node* insert(char c, node* ptr);
char* to_lower(char* s);
void rec_unload(node* ptr);

// root node
node root;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char* lower = to_lower((char*) word);

    int i = 0;

    node* ptr = &root;

    while(lower[i] != '\0')
    {
        if(ptr == NULL)
        {
            free(lower);
            return false;
        }

        if(lower[i] == '\'')
            ptr = ptr->children[26];
        else
            ptr = ptr->children[lower[i] - 'a'];
        i++;
    }

    free(lower);

    if(ptr == NULL || ptr->is_word == false)
        return false;
    else
        return true;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open dictionary
    FILE* fp = fopen(dictionary, "r");

    // if you can't open
    if(fp == NULL)
        return false;

    // buffer
    char buffer[LENGTH + 1];

    // use fscanf to get the string, then break it down
    while(fscanf(fp, "%s", buffer) == 1)
    {

        // set a node ptr pointing to root
        node* ptr = &root;

        // insert it in the trie
        for(int i = 0; buffer[i] != '\0'; i++)
        {
            ptr = insert(buffer[i], ptr);
        }

        // marker that this is a new word
        if(ptr->is_word == false)
            ptr->is_word = true;

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
    node* ptr = &root;

    for(int i = 0; i < 27; i++)
        if(ptr->children[i] != NULL)
            rec_unload(ptr->children[i]);

    return true;
}


// pass it a pointer to the blocks root points to (27)
void rec_unload(node* ptr)
{
    for(int i = 0; i < 27; i++)
    {
        if(ptr->children[i] != NULL)
            rec_unload(ptr->children[i]);
    }

    free(ptr);
}

/**
 * Insert a character into trie
 */
node* insert(char c, node* ptr)
{
    int index = 0;

    if(c == '\'')
        index = 26;
    else
        index = c - 'a';

    if(ptr->children[index] == NULL)
    {
        node* new_ptr = malloc(sizeof(node));
        ptr->children[index] = new_ptr;
    }

    // return ptr to new node
    return ptr->children[index];
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
