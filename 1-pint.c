#include "monty.h"

/**
 * pint - prints the vlaue at the top of the stack
 * followed by a new line
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 *
 * Description: if the stack is empty,
 * print an error message and exit with
 * the status EXIT_FAILURE
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf (stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
