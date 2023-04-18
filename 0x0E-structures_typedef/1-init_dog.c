#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * init_dog - Initialize a struct dog
 * @d: Pointer to struct dog
 * @name: Name of the dog
 * @owner: Owner of the dog
 * @age: Age of the dog
 *
 * Return: None
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->owner = owner;
		d->age = age;
	}
}
