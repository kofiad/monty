#include "monty.h"

/**
 * nop - opcode that doesn't do anything
 * @stack: double pointer to the top of the stack (unused)
 * @line_number: current line number in the bytecode file (unused)
 *
 * Description: This function is designed to do nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
