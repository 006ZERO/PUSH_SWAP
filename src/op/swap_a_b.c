/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:52:24 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:52:25 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** swap_a: Swaps the first two elements at the top of stack a
** a: Pointer to stack a
** Does nothing if stack has less than 2 elements
** Prints "sa\n" to stdout
**  Note :
**    t_node *first = a->top;      a->top is a pointer (memory address)
**   int value = a->top->value;   a->top->value is an integer (the actual number)
**		House at address 0x100:
**  - Address: 0x100  ← This is `a->top`
**  - People inside: 3 people ← This is `a->top->value`
*/
void	swap_a(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sa\n", 3);
	op_tracker("sa", 0);
}

/*
** swap_b: Swaps the first two elements at the top of stack b
** b: Pointer to stack b
** Does nothing if stack has less than 2 elements
** Prints "sb\n" to stdout
*/
void	swap_b(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sb\n", 3);
	op_tracker("sb", 0);
}

/*
** swap_a_no_print: Swaps first two elements without printing
** a: Pointer to stack a
** Internal helper function for swap_ss
*/
void	swap_a_no_print(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

/*
** swap_b_no_print: Swaps first two elements without printing
** b: Pointer to stack b
** Internal helper function for swap_ss
*/
void	swap_b_no_print(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

/*
** swap_ss: Swaps first two elements of both stacks a and b
** a: Pointer to stack a
** b: Pointer to stack b
** Only performs swap if BOTH stacks have at least 2 elements
** Prints "ss\n" to stdout (only once)
*/
void	swap_ss(t_stack *a, t_stack *b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = 0;
	swapped_b = 0;
	if (a && a->top && a->top->next)
		swapped_a = 1;
	if (b && b->top && b->top->next)
		swapped_b = 1;
	if (swapped_a && swapped_b)
	{
		swap_a_no_print(a);
		swap_b_no_print(b);
		write(1, "ss\n", 3);
		op_tracker("ss", 0);
	}
}
