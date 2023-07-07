#include "hash_tables.h"
/**
 * hash_djb2 - implements the djb2 algorithm
 * @str: the string to be hashed
 *
 * Return: the hash value of the string
*/
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash_key = 5381;
	int character;

	while ((character = *str++))
		hash_key = ((hash_key << 5) + hash_key) + character;

	return (hash_key);
}
