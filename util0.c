#include "monty.h"

void execute(void);

/**
 * node_alloc - allocs memory for stack item
 *
 * Return: pointer to allocated stack item
 * Description: prints error and exit if malloc fails
*/
void *node_alloc(void)
{
	stack_t *tmp = malloc(sizeof(stack_t));

	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
	return (tmp);
}

/**
 * execute - finds and calls function corresponding to opcode
*/
void execute(void)
{
	short i = 0;
	char *opcode;
	instruction_t action[] = {
		{"pall", print_all},
		{"push", push},
		{"pop", pop},
		{"pint", print_top},
		{"pchar", print_top},
		{"pstr", print_all},
		{"swap", swap},
		{"add", calc},
		{"sub", calc},
		{"div", calc},
		{"mul", calc},
		{"mod", calc},
		{"nop", nop},
		{"rotl", rot},
		{"rotr", rot},
		{"stack", mode},
		{"queue", mode},
		{NULL, NULL}
	};

	strcpy(bundle.tmp, bundle.line_text);
	opcode = strtok(bundle.tmp, DELIM);
	bundle.line_number++;
	if (!opcode || *opcode == '#')
		return;
	while (action[i].opcode)
	{
		if (strcmp(opcode, action[i++].opcode) == 0)
		{
			bundle.opcode = strtok(bundle.line_text, DELIM);
			if (strcmp(opcode, "push") == 0)
				action[--i].f(bundle.mode == _stack ? &bundle.stack
				: &bundle.queue, bundle.line_number);
			else
				action[--i].f(&bundle.stack, bundle.line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", bundle.line_number, opcode);
	bundle.status = EXIT_FAILURE;
	shutdown();
}

/**
 * is_integer - checks if a string contains only integers
 * @str: string to be checked
 *
 * Return: true if str contains only integers else false
*/
bool is_integer(char *str)
{
	char *tmp = str;

	if (*tmp == '-')
		tmp++;
	while (*tmp)
		if (!isdigit(*tmp++))
			return (false);
	return (true);
}

/**
 * shutdown - terminates program
 *
 * Description: exits with appropriate status code and
 * prints error message on error
*/
void shutdown(void)
{
	stack_t *tmp;

	fclose(bundle.file);
	while ((tmp = bundle.stack))
	{
		bundle.stack = bundle.stack->next;
		free(tmp);
	}
	exit(bundle.status);
}

/**
 * div_by_zero - e
*/
void div_by_zero(void)
{
	fprintf(stderr, "L%d: division by zero\n", bundle.line_number);
	bundle.status = EXIT_FAILURE;
	shutdown();
}
