/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define MAX 4294967295 // max int size
#define BITS 12000000 // size of array * 8
#define BYTE 8

#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

// bloom filter with space for 143091 chars (8 bits per word in dict)
char bloom[1500000];

// counter for size of dictionary
int counter = 0;

// seed for murmur hash
int seed = 50;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char buffer[strlen(word) + 1];
    int len = strlen(word);

    for(int i = 0; i < len; i++)
    {
        buffer[i] = tolower(word[i]);
    }

    buffer[len] = '\0';

    // get different hash values; these will all be values
    uint32_t sfh = SFH(buffer, len) % BITS;
    uint32_t oaat = OAAT((char*) buffer, len) % BITS;
    uint32_t mur = murmur(buffer, len, seed) % BITS;

    // turn on bits
    int index = sfh / BYTE; // where to place in array
    int offset = sfh % BYTE; // bit to turn on

    if(!(bloom[index] & (1 << offset)))
        return false;

    index = oaat / BYTE;
    offset = oaat % BYTE;

    if(!(bloom[index] & (1 << offset)))
        return false;

    index = mur / BYTE;
    offset = mur % BYTE;

    if(!(bloom[index] & (1 << offset)))
        return false;

    return true;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open dictionary
    FILE* fp = fopen(dictionary, "r");

    // return false if you couldn't open the dictionary
    if(fp == NULL)
        return false;

    // create a buffer to hold the word
    char buffer[LENGTH + 1];

    // read in word
    while(fscanf(fp, "%s", buffer) == 1)
    {
        counter++;

        // get different hash values; these will all be values
        uint32_t sfh = SFH(buffer, strlen(buffer)) % BITS;
        uint32_t oaat = OAAT(buffer, strlen(buffer)) % BITS;
        uint32_t mur = murmur(buffer, strlen(buffer), seed) % BITS;

        // turn on bits
        int index = sfh / BYTE; // where to place in array
        int offset = sfh % BYTE; // bit to turn on

        bloom[index] = bloom[index] | (1 << offset);

        index = oaat / BYTE;
        offset = oaat % BYTE;

        bloom[index] = bloom[index] | (1 << offset);

        index = mur / BYTE;
        offset = mur % BYTE;

        bloom[index] = bloom[index] | (1 << offset);
    }

    fclose(fp);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    return true;
}

/**
 * HASH FUNCTIONS
 */

// Paul Hsieh's SuperFastHash
uint32_t SFH(const char* data, int len) 
{

    uint32_t hash = len, tmp;
    int rem = 0;

    if (len <= 0 || data == NULL) 
        return 0;

    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char)*data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

// Bob Jenkin's One-at-a-time hash
uint32_t OAAT(char* key, size_t len)
{
    uint32_t hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

// Murmur hash
uint32_t murmur(const char *key, uint32_t len, uint32_t seed)
{
	static const uint32_t c1 = 0xcc9e2d51;
	static const uint32_t c2 = 0x1b873593;
	static const uint32_t r1 = 15;
	static const uint32_t r2 = 13;
	static const uint32_t m = 5;
	static const uint32_t n = 0xe6546b64;

	uint32_t hash = seed;

	const int nblocks = len / 4;
	const uint32_t *blocks = (const uint32_t *) key;
	int i;
	for (i = 0; i < nblocks; i++) {
		uint32_t k = blocks[i];
		k *= c1;
		k = (k << r1) | (k >> (32 - r1));
		k *= c2;

		hash ^= k;
		hash = ((hash << r2) | (hash >> (32 - r2))) * m + n;
	}

	const uint8_t *tail = (const uint8_t *) (key + nblocks * 4);
	uint32_t k1 = 0;

	switch (len & 3) {
	case 3:
		k1 ^= tail[2] << 16;
	case 2:
		k1 ^= tail[1] << 8;
	case 1:
		k1 ^= tail[0];

		k1 *= c1;
		k1 = (k1 << r1) | (k1 >> (32 - r1));
		k1 *= c2;
		hash ^= k1;
	}

	hash ^= len;
	hash ^= (hash >> 16);
	hash *= 0x85ebca6b;
	hash ^= (hash >> 13);
	hash *= 0xc2b2ae35;
	hash ^= (hash >> 16);

	return hash;
}
