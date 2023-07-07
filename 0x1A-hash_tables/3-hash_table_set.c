#include "hash_tables.h"
/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table to addd or update the key/value to
 * @key: the key of the element
 * @value: the value associated with the key
 *
 * Return: 1 (success), 0 (otherwise)
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hsh_index, hsh_size;
	hash_node_t *new_entry;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	hsh_size = ht->size;
	hsh_index = key_index((const unsigned char *)key, hsh_size);

	if (ht->array[hsh_index] != NULL && strcmp(ht->array[hsh_index]->key, key))
	{
		ht->array[hsh_index]->value = strdup(value);
		return (1);
	}

	new_entry = malloc(sizeof(hash_node_t));

	if (new_entry == NULL)
		return (0);

	new_entry->key = strdup(key);
	new_entry->value = strdup(value);
	new_entry->next = ht->array[hsh_index];
	ht->array[hsh_index] = new_entry;
	return (1);
}
