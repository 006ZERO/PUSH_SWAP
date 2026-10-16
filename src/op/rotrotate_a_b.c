/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotrotate_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:52:15 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:52:17 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rra: Reverse rotates stack a - last becomes first
** Uses bottom pointer for O(1) access to last element
** a: Stack to reverse rotate
** Prints "rra\n" to stdout
*/
void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*second_last;

	if (!a || !a->top || !a->top->next)
		return ;
	second_last = a->top;
	while (second_last->next != a->bottom)
		second_last = second_last->next;
	last = a->bottom;
	last->next = a->top;
	a->top = last;
	a->bottom = second_last;
	a->bottom->next = NULL;
	write(1, "rra\n", 4);
	op_tracker("rra", 0);
}

/*
** rrb: Reverse rotates stack b - last becomes first
** b: Stack to reverse rotate
** Prints "rrb\n" to stdout
*/
void	rrb(t_stack *b)
{
	t_node	*last;
	t_node	*second_last;

	if (!b || !b->top || !b->top->next)
		return ;
	second_last = b->top;
	while (second_last->next != b->bottom)
		second_last = second_last->next;
	last = b->bottom;
	last->next = b->top;
	b->top = last;
	b->bottom = second_last;
	b->bottom->next = NULL;
	write(1, "rrb\n", 4);
	op_tracker("rrb", 0);
}

/*
** rra_no_print: Reverse rotates stack a without printing
** a: Stack to reverse rotate
*/
void	rra_no_print(t_stack *a)
{
	t_node	*last;
	t_node	*second_last;

	if (!a || !a->top || !a->top->next)
		return ;
	second_last = a->top;
	while (second_last->next != a->bottom)
		second_last = second_last->next;
	last = a->bottom;
	last->next = a->top;
	a->top = last;
	a->bottom = second_last;
	a->bottom->next = NULL;
}

/*
** rrb_no_print: Reverse rotates stack b without printing
** b: Stack to reverse rotate
*/
void	rrb_no_print(t_stack *b)
{
	t_node	*last;
	t_node	*second_last;

	if (!b || !b->top || !b->top->next)
		return ;
	second_last = b->top;
	while (second_last->next != b->bottom)
		second_last = second_last->next;
	last = b->bottom;
	last->next = b->top;
	b->top = last;
	b->bottom = second_last;
	b->bottom->next = NULL;
}

/*
** rrr: Reverse rotates both stacks a and b
** a: First stack to reverse rotate
** b: Second stack to reverse rotate
** Prints "rrr\n" to stdout
*/
void	rrr(t_stack *a, t_stack *b)
{
	if (a && a->top && a->top->next && b && b->top && b->top->next)
	{
		rra_no_print(a);
		rrb_no_print(b);
		write(1, "rrr\n", 4);
		op_tracker("rrr", 0);
	}
}
