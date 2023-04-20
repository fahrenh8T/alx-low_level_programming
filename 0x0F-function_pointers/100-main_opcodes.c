#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the opcodes of its own main function
 * @argc: the number of arguments
 * @argv: array of actual arguments
 *
 * Return: 0 on success, 1 if the number of arguments is incorrect,
 *         2 if the number of bytes is negative
 */
int main(int argc, char *argv[])
{
	unsigned char *opcode = (unsigned char *)main;
	int i;
	int num_bytes = atoi(argv[1]);

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", *(opcode + i));
	}

	printf("\n");
	return (0);
}
