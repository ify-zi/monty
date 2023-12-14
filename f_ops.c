#include "monty.h"

/**
 * f_swap - swaps the element
 * @stack: pointer to the head
 * @line_number: where the line number appears
 * Return: nothing if success
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *p1, *p2;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		f_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if (*stack)
	{
		p1 = *stack;
		p2 = p1->next;
		*stack = p2;
		p1->next = p2->next;
		if (p2->next != NULL)
		{
			p2->next->prev = p1;
		}
		p2->prev = NULL;
		p2->next = p1;
		p1->prev = p2;
	}
}

/**
 * f_add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: command line number
 * Return: nothing if success
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *p1, *p2;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		p1 = *stack;
		p2 = p1->next;
		p2->n += p1->n;
		*stack = p2;
		(*stack)->prev = NULL;
		free(p1);
	}
}

/**
 * f_sub - subtracts the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: command line number
 * Return: nothing
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *p1, *p2;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(file);
		f_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		p1 = *stack;
		p2 = p1->next;
		p2->n -= p1->n;
		*stack = p2;
		(*stack)->prev = NULL;
		free(p1);
	}
}

/**
 * f_div - divides the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: command_line number
 * Return: nothing
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *p1, *p2;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(file);
		free(*stack);
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
		p2->n /= p1->n;
		*stack = p2;
		(*stack)->prev = NULL;
		free(p1);
	}
}

/**
 * f_mul - multiples the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: command line number
 * Return: nothing
 */

void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *p1, *p2;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		p1 = *stack;
		p2 = p1->next;
		p2->n *= p1->n;
		*stack = p1;
		(*stack)->prev = NULL;
		free(p1);
	}
}
