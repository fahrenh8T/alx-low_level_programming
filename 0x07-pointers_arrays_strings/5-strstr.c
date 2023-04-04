#include "main.h"
/**
 * _strstr - locate the first occurrence of a substring
 * @haystack: string to be searched
 * @needle: substring
 *
 * Return:  pointer to the beginning of the located substring or NULL
*/
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
			break;
		}
		if (needle[j] == '\0')
		return (haystack + i);
	}
	return (NULL);
}
