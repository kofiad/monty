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

/**
 * get_op_func - selects the correct functin to perform
 * the operation asked by the user
 * @s: the operation code
 *
 * Return: A pointer to the function that corresponds to the opcode
 * if s does not match any opcode, return NULL
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

/**
 * free_stack - frees a stack_t stack
 * @stack: the stack to be freed
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
