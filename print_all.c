#include "monty.h"

/**
 * print_all - prints all elements in stack
 * @stack: stack top
 * @line_number: script line under execution
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);
	if (stack && *stack)
	{
		tmp = *stack;
		if (strcmp(bundle.opcode, "pall") == 0)
		{
			while (tmp)
			{
				printf("%d\n", tmp->n);
				fflush(stdout);
				tmp = tmp->next;
			}
		}
		else if (strcmp(bundle.opcode, "pstr") == 0)
		{
			while (tmp)
			{
				if (!__isascii(tmp->n) || tmp->n == 0)
					break;
				printf("%c", tmp->n);
				tmp = tmp->next;
			}
		}
	}
	if (strcmp(bundle.opcode, "pstr") == 0)
		putchar('\n');
}
