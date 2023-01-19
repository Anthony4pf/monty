#include "monty.h"

/**
*check_if_integer - check if a string is an integer
*@str: string
*Return: 1 if integer or 0 if otherwise
*/

int check_if_integer(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
