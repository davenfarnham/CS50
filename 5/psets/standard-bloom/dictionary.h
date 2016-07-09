/****************************************************************************
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 ***************************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <stdint.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/*
 * Paul Hsieh's Superfast Hash function
 */
uint32_t SFH(const char* data, int len);

/*
 * Bob Jenkin's One-at-a-time hash function
 */
uint32_t OAAT(char* key, size_t len);

/*
 * Murmur hash function
 */
uint32_t murmur(const char *key, uint32_t len, uint32_t seed);

#endif // DICTIONARY_H
