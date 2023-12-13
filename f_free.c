#include "monty.h"

/**
 *  f_free - function that frees the mem of stack
 *  @stack: pointer to the top.
 *  Return: Void
 */

void f_free(stack_t *stack)
{
	if (stack)
	{
		f_free(stack->next);
		free(stack);
	}
}
