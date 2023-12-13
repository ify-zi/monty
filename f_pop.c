#include "monty.h"

/**
 * f_pop - removes an element from the stack
 * @stack: pointer to stack top
 * @line_number: the line number where command at
 * Return: return nothing on sucess, Exit_failure on failure
 */

void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *element;

	if ((stack == NULL) || (*stack == NULL))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	element = *stack;
	*stack = (*stack)->next;
	if (element->next)
	{
		element->next->prev = NULL;
	}
	free(element);
}
