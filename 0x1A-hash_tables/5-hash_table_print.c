#include "hash_tables.h"
/**
 * hash_table_print - prints a hash table
 * @ht: the hsh table to print
 *
 * Return: nothing
*/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *nod;
	unsigned long int cnt = 0, i = 0;

	if (ht != NULL)
	{
		printf("{");
		for (cnt = 0; cnt < ht->size; cnt++)
		{
			nod = ht->array[cnt];
			while (nod != NULL)
			{
				if (i != 0)
					printf(", ");
				i = 1;
				printf("'%s': '%s'", nod->key, nod->value);
				nod = nod->next;
			}
		}
		printf("}\n");
	}
}
