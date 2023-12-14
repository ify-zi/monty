#include "monty.h"

/**
 * f_mod - function that finds the modulus of top two elements
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Return: see below
 */

void f_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *p1, *p2;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(file);
		f_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(file);
		f_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		p1 = *stack;
		p2 = p1->next;
		p2->n %= p1->n;
		*stack = p2;
		(*stack)->prev = NULL;
		free(p1);
	}
}
