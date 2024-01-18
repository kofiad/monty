#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}



/**
 * getline - function reads a line from the given file pointer
 * into a dynamically allocated buffer.
 * @fp: file pointeer
 * Return: returns NULL on failure.
 * line on success
 */
char *getline(FILE *fp)
{
	char ch;
	int i = 0;
	char *line = malloc(BUFFER_SIZE);
	char *expanded_line = realloc(line, i + BUFFER_SIZE);

	if (!line)
		return (NULL);
	while ((ch = fgetc(fp)) != EOF && ch != '\n')
	{
		line[i++] = ch;
		/*If buffer is full, expand it*/
		if (i % BUFFER_SIZE == 0)
		{
			if (!expanded_line)
			{
				free(line);
				return (NULL);
			}
			line = expanded_line;
		}
	}

	/*If we didn't read anything before EOF or an error, clean up and exit*/
	if (i == 0 && (ch == EOF || ferror(fp)))
	{
		free(line);
		return (NULL);
	}

	/*Null-terminate the string*/
	line[i] = '\0';

	return (line);
}
