#include "monty.h"

/**
 * _swap - function that swaps the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: scrpit line number
 *
 * Description: if the stack contains less than two elements
 * print and error message and exit with the status EXIT_FAILURE
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;
	if (second->next)
		second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;

	if (second->prev)
		ssecond->prev->next = second;
	else
		*stack = second;
}
