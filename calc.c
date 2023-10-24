#include "monty.h"

void calc(stack_t **, unsigned int);

/**
* calc - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void calc(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack && *stack && (*stack)->next)
	{
		if (strcmp(bundle.opcode, "add") == 0)
		{
			result = (*stack)->next->n + (*stack)->n;
		}
		else if (strcmp(bundle.opcode, "sub") == 0)
		{
			result = (*stack)->next->n - (*stack)->n;
		}
		else if (strcmp(bundle.opcode, "mul") == 0)
		{
			result = (*stack)->next->n * (*stack)->n;
		}
		else if (strcmp(bundle.opcode, "div") == 0)
		{
			if (!(*stack)->n)
				div_by_zero();
			result = (*stack)->next->n / (*stack)->n;
		}
		else if (strcmp(bundle.opcode, "mod") == 0)
		{
			if (!(*stack)->n)
				div_by_zero();
			result = (*stack)->next->n % (*stack)->n;
		}
		pop_helper(stack);
		pop_helper(stack);
		push_helper(stack, result);
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n"
						, line_number, bundle.opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}
