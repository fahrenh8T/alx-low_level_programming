#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table to delete
*/
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *hash_table_head = ht;
	hash_node_t *nod, *next_nod;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			nod = ht->array[i];
			while (nod != NULL)
			{
				next_nod = nod->next;
				free(nod->key);
				free(nod->value);
				free(nod);
				nod = next_nod;
			}
		}
	}
	free(hash_table_head->array);
	free(hash_table_head);
}
