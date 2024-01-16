#include "monty.h"

/**
 * _push - function to push an element to the stack
 * @stack: stack
 * @arg: argument
 * @line_number: number of the line
 */
void _push(stack_t **stack, char *arg, unsigned int line_number)
{
	int n;

	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*Check if argument is a valid integer*/
	if (arg == NULL || _isnumber(arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push interger\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*Convert the argument to an integer using atoi*/
	n = atoi(arg);
	new_node->n = n;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * _pall - function to print all elemts in the stack
 * @stack: stack
 */
void _pall(stack_t **stack)
{
	stack_t  *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
