#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 *
 * Description: if the empty, print an error message
 * and exit with the status EXIT_FAILURE.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
			(*stack)->prev =  NULL;

	free(temp);
}
