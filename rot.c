#include "monty.h"

/**
 * rot - prints all elements in stack
 * @stack: stack top
 * @line_number: script line under execution
 */
void rot(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	UNUSED(line_number);
	if (stack && *stack && (*stack)->next)
	{
		top = *stack;
		bottom = top;
		while ((bottom = bottom->next) && bottom->next)
			;
		if (strcmp(bundle.opcode, "rotl") == 0)
		{
			top->next->prev = NULL;
			*stack = top->next;
			bottom->next = top;
			top->next = NULL;
			top->prev = bottom;
		}
		else if (strcmp(bundle.opcode, "rotr") == 0)
		{
			bottom->prev->next = NULL;
			bottom->next = *stack;
			bottom->next->prev = bottom;
			bottom->prev = NULL;
			*stack = bottom;
		}
	}
}
