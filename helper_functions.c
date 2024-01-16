#include "monty.h"

/**
 * _isnumber - checks if string is a number
 * @s: pointer to string
 * Return: 1 if string is a valid number
 * 0 otherwise
 */
int _isnumber(char *s)
{
	int i = 0;

	/*Check for positive and negative signs and skip if present*/
	if (s[0] == '+' || s[0] == '-')
	{
		i++;
	}
	/*Check if character is a digit*/
	for (; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}
