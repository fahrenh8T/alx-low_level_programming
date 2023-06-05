#include "main.h"
/**
 * _abs - compute the absolute value of an integer
 * @i: integer (int)
 * Return: 0 (success)
*/
int _abs(int i)
{
	if (i >= 0)
	{
		return (i);
	}
	else
	{
		return (i * -1);
	}
}
