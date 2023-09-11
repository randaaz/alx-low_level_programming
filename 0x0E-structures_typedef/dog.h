#ifndef DOG_H
#define DOG_H

/**
 * struct dog -  Describes a dog with its name, age, and owner
 *@name: The name of the dog
 *@age: The age of the dog
 *@owner: The owner of the dog
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner;
		void print_dog(struct dog *d);
		typedef struct dog dog_t;
		int _len(const char *ptr);
		dog_t *new_dog(char *name, float age, char *owner);
		void free_dog(dog_t *d);

#endif
