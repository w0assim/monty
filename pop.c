#include "monty.h"

/**
* pop - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
	{
		pop_helper(stack);
	}
	else
	{
		fprintf(stderr, "L%d: can't %s an empty stack\n"
						, line_number, bundle.opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}

/**
* pop_helper - removes last element from stack
* @stack: stack top
*/
void pop_helper(stack_t **stack)
{
	stack_t *tmp = (*stack)->next;

	if (tmp)
		tmp->prev = NULL;

	free(*stack);
	*stack = tmp;
}
