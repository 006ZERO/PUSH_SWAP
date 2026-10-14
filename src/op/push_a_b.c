
#include "push_swap.h"

/*
** push_b: Takes first element at top of a and puts it at top of b
** a: Source stack
** b: Destination stack
** Prints "pb\n" to stdout
** First check: if `a` is NULL,
it means it does not point to a valid memory location. -> (segmentation fault)
** Second check: if `a->top` is NULL, it means the stack exists but is empty,
** so there is no element to move or access.
*/
void	push_b(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !a->top || !b)
		return ;
	node = a->top;
	a->top = a->top->next;
	a->size--;
	if (a->top == NULL)
		a->bottom = NULL;
	node->next = b->top;
	b->top = node;
	b->size++;
	if (b->size == 1)
		b->bottom = node;
	write(1, "pb\n", 3);
	op_tracker("pb", 0);
}

/*
** push_a: Takes first element at top of b and puts it at top of a
** a: Destination stack
** b: Source stack
** Prints "pa\n" to stdout
*/
void	push_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !b || !b->top)
		return ;
	node = b->top;
	b->top = b->top->next;
	b->size--;
	if (b->top == NULL)
		b->bottom = NULL;
	node->next = a->top;
	a->top = node;
	a->size++;
	if (a->size == 1)
		a->bottom = node;
	write(1, "pa\n", 3);
	op_tracker("pa", 0);
}
