#include <stdlib.h>
#include "dog.h"
/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to a new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int x, y, z = 0;
	dog_t *dog;

	if (name == NULL || owner == NULL)
		return (NULL);
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	for (x = 0; name[x]; x++)
		;
	x++;
	dog->name = malloc(x * sizeof(char));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	while (z < x)
	{
		dog->name[z] = name[z];
		z++;
	}
	dog->age = age;
	for (y = 0; owner[y]; y++)
		;
	y++;
	dog->owner = malloc(y * sizeof(char));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	while (z < y)
	{
		dog->owner[z] = owner[z];
		z++;
	}
	return (dog);
}
