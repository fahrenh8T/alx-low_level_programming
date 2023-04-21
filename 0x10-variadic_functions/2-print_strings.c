#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_strings - prints strings
 * @separator: the string to be printed
 * @n: number of strings passed
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *sep = NULL;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		sep = va_arg(args, char *);

		if (sep == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", sep);
		}

		if (i != n - 1 && separator != NULL)
		{
			printf("%s", separator);
		}
	}

	va_end(args);

	printf("\n");
}
