#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_all - prints anyhing
 * @format: list of types of arguments passed
*/
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	char *str;
	char *form = "";

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", form, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", form, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", form, va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);

				if (str == NULL)
					str = "(nil)";
				printf("%s%s", form, str);
				break;
			default:
				i++;
				continue;
		}
		form = ", ";
		i++;
	}

	va_end(args);
	printf("\n");
}
