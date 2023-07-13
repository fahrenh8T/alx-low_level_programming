#include "hash_tables.h"
/**
 * hash_table_get - retriives a value associated with a key
 * @ht: the hash table to look into
 * @key: the key to look for
 *
 * Return: the value associated with the key, or NULL (if not found)
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *nod;
	unsigned long int hsh_index;

	if (key == NULL || ht == NULL)
		return (NULL);

	hsh_index = key_index((const unsigned char *)key, ht->size);
	nod = ht->array[hsh_index];

	for (; nod != NULL; nod = nod->next)
	{
		if (strcmp(nod->key, key) == 0)
			return (nod->value);
	}

	return (NULL);
}
