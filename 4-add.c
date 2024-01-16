#include "monty.h"

/**
 * add - add the top two elemets of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 *
 * Description: if the stack contains less than two elements
 * print an error message and exit with the status EXIT_FAILURE
 * the result is storec in the second top element
 * of the stack, and the top element is removed
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: cant add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	/*Call _pop function to remove top element*/
	pop(stack, line_number);
	/*Store result in new top element*/
	(*stack)->n = sum;
}
