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
	char *val_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	{
		return (0);
	}

	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);

	hsh_index = key_index((const unsigned char *)key, ht->size);
	for (hsh_size = hsh_index; ht->array[hsh_size]; hsh_size++)
	{
		if (strcmp(ht->array[hsh_size]->key, key) == 0)
		{
			free(ht->array[hsh_size]->value);
			ht->array[hsh_size]->value = val_copy;
			return (1);
		}
	}

	new_entry = malloc(sizeof(hash_node_t));
	if (new_entry == NULL)
		free(val_copy);
	return (0);

	new_entry->key = strdup(key);
	if (new_entry->key == NULL)
		free(new_entry);
	return (0);

	new_entry->value = val_copy;
	new_entry->next = ht->array[hsh_index];
	ht->array[hsh_index] = new_entry;

	return (1);
}
