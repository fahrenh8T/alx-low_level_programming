#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the hash table
 *
 * Return: pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ntable;
	unsigned long int i;

	ntable = malloc(sizeof(shash_table_t));
	if (ntable == NULL)
		return (NULL);
	ntable->size = size;
	ntable->shead = NULL;
	ntable->stail = NULL;
	ntable->array = malloc(sizeof(shash_node_t) * size);
	if (ntable->array == NULL)
	{
		free(ntable);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		ntable->array[i] = NULL;
	}
	return (ntable);
}

/**
 * make_shash_node - makes a node for the sorted hash table
 * @key: key for the data
 * @value: data to be stored
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *nnode;

	nnode = malloc(sizeof(shash_node_t));
	if (nnode == NULL)
		return (NULL);
	nnode->key = strdup(key);
	if (nnode->key == NULL)
	{
		free(nnode);
		return (NULL);
	}
	nnode->value = strdup(value);
	if (nnode->value == NULL)
	{
		free(nnode->key);
		free(nnode);
		return (NULL);
	}
	nnode->next = nnode->snext = nnode->sprev = NULL;
	return (nnode);
}

/**
 * add_to_sorted_list - add a node to the sorted (by key's ASCII) linked list
 * @table: the sorted hash table
 * @node: the node to add
 *
 * Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *crrnt_node;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	crrnt_node = table->shead;
	while (crrnt_node != NULL)
	{
		if (strcmp(node->key, crrnt_node->key) < 0)
		{
			node->snext = crrnt_node;
			node->sprev = crrnt_node->sprev;
			crrnt_node->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		crrnt_node = crrnt_node->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key to the data
 * @value: data to add
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int indx;
	char *new_value;
	shash_node_t *nnode, *crrnt_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	indx = key_index((const unsigned char *)key, ht->size);
	crrnt_node = ht->array[indx];
	while (crrnt_node != NULL)
	{
		if (strcmp(crrnt_node->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(crrnt_node->value);
			crrnt_node->value = new_value;
			return (1);
		}
		crrnt_node = crrnt_node->next;
	}
	nnode = make_shash_node(key, value);
	if (nnode == NULL)
		return (0);
	nnode->next = ht->array[indx];
	ht->array[indx] = nnode;
	add_to_sorted_list(ht, nnode);
	return (1);
}

/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: hash table
 * @key: key to the data
 *
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *crrnt_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	crrnt_node = ht->array[index];
	while (crrnt_node != NULL)
	{
		if (strcmp(crrnt_node->key, key) == 0)
			return (crrnt_node->value);
		crrnt_node = crrnt_node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *crrnt_node;
	char flag = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	crrnt_node = ht->shead;
	while (crrnt_node != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", crrnt_node->key, crrnt_node->value);
		flag = 1;
		crrnt_node = crrnt_node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *crrnt_node;
	char flag = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	crrnt_node = ht->stail;
	while (crrnt_node != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", crrnt_node->key, crrnt_node->value);
		flag = 1;
		crrnt_node = crrnt_node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *next_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			next_node = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next_node;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
