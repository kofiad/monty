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
 * @fd: file pointeer
 * Return: returns NULL on failure.
 * line on success
 */
ssize_t getline(char **buffer, size_t *size, FILE *fd) {
	if (!buffer || !size || !fd) {
		return -1;
	}

	if (*buffer == NULL || *size == 0) {
		*buffer = malloc(BUFFER_SIZE);
		if (!*buffer) return -1;
		*size = BUFFER_SIZE;
	}

	char ch;
	size_t i = 0;
	while ((ch = fgetc(fd)) != EOF && ch != '\n') {
		(*buffer)[i++] = ch;

		/*If buffer is full, expand it*/
		if (i >= *size) {
			*size *= 2;
			char *expanded_buffer = realloc(*buffer, *size);
			if (!expanded_buffer) {
				free(*buffer);
				*buffer = NULL;
				return -1;
			}
			*buffer = expanded_buffer;
		}
	}

	/*If we didn't read anything before EOF or an error, clean up and exit*/
	if (i == 0 && (ch == EOF || ferror(fd))) {
		free(*buffer);
		*buffer = NULL;
		return -1;
	}

	/*Null-terminate the string*/
	(*buffer)[i] = '\0';

	return i;
}
