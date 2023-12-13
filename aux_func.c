#include "monty.h"

/**
 * _isdigit - check for int
 * @str: string literal
 * Return: 1 if true and 0 if false
 */

int _isdigit(char *str)
{
	int i = 0;

	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
