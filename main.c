#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Argument count. The number of arguments passed to the program.
 * It should be 2 for a Monty interpreter:
 * the program name and the bytecode file.
 * @argv: Argument vector. An array of strings representing the arguments.
 * argv[0] is the program name, argv[1] is the bytecode file.
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, "\n\t\r ");
		 /*skip blank lines and comments*/
		if (opcode == NULL || opcode[0] == '#')
			continue;

		func = get_op_func(opcode);
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}

		func(&stack, line_number);
	}

	free(line);
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
