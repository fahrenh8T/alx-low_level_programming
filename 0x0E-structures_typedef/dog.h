#ifndef dog_h
#define dog_h
/**
 * struct dog - type of struct
 * @name: name of the dog
 * @owner: name of the owner
 * @age: age element
 */

struct dog
{
	char *name;
	char *owner;
	float age;
};
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif /*dog_h*/
