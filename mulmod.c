#include "monty.h"

/**
 * mul - A function that multiplies the top two elements of the stack.
 * @stack: Ptr to a ptr to top node of the stack
 * @line_number: line nmber.
 * Return: void.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		Errmes(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod - An fxn tha computing the remainder of the division
 * of the top two elements of the stack.
 * @stack: Ptr to a ptr to top node of the stack
 * @line_number: line nmbr.
 * Return: void.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		Errmes(8, line_number, "mod");


	if ((*stack)->n == 0)
		Errmes(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
