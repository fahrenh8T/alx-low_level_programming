#include <stdio.h>
/**
 * print_message - function prints a message before execution of main
*/
void print_message(void) __attribute__((constructor));

void print_message(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
