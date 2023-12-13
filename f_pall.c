#include "monty.h"

/**
 * f_pall - print all elemetn in stack
 * @stack: pointer to head of the stack
 * @line_number: command line number
 * Return: nothing if succes and exit_failure is it fails
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element;
	(void)line_number;

	element = *stack;

	while (element != NULL)
	{
		printf("%d", element->n);
		element = element->next;
		printf("\n");
	}
}
