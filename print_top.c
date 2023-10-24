#include "monty.h"

/**
 * print_top - prints value atop the stack
 * @stack: stack top
 * @line_number: script line under execution
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
	{
		if (strcmp(bundle.opcode, "pint") == 0)
		{
			printf("%d\n", (*stack)->n);
		}
		else if (strcmp(bundle.opcode, "pchar") == 0)
		{
			if (!__isascii((*stack)->n))
			{
				fprintf(stderr, "L%d: can't %s, value out of range\n"
						, line_number, bundle.opcode);
				bundle.status = EXIT_FAILURE;
				shutdown();
			}
			printf("%c\n", (*stack)->n);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack empty\n", line_number, bundle.opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}
