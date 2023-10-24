#include "monty.h"

/**
* mode - prints all elements in stack
* @stack: stack top
* @line_number: script line under execution
*/
void mode(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	if (strcmp("stack", bundle.opcode) == 0 && bundle.mode != _stack)
		bundle.mode = _stack;
	else if (strcmp("queue", bundle.opcode) == 0 && bundle.mode != _queue)
		bundle.mode = _queue;
}
