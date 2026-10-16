/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:52:04 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:52:06 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ra: Rotates stack a - first becomes last (O(1) with bottom pointer)
** a: Stack to rotate
** Prints "ra\n" to stdout
*/
void	ra(t_stack *a)
{
	t_node	*first;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	a->top = a->top->next;
	a->bottom->next = first;
	a->bottom = first;
	first->next = NULL;
	write(1, "ra\n", 3);
	op_tracker("ra", 0);
}

/*
** rb: Rotates stack b - first becomes last (O(1) with bottom pointer)
** b: Stack to rotate
** Prints "rb\n" to stdout
*/
void	rb(t_stack *b)
{
	t_node	*first;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	b->top = b->top->next;
	b->bottom->next = first;
	b->bottom = first;
	first->next = NULL;
	write(1, "rb\n", 3);
	op_tracker("rb", 0);
}

/*
** ra_no_print: Rotates stack a without printing
** a: Stack to rotate
*/
void	ra_no_print(t_stack *a)
{
	t_node	*first;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	a->top = a->top->next;
	a->bottom->next = first;
	a->bottom = first;
	first->next = NULL;
}

/*
** rb_no_print: Rotates stack b without printing
** b: Stack to rotate
*/
void	rb_no_print(t_stack *b)
{
	t_node	*first;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	b->top = b->top->next;
	b->bottom->next = first;
	b->bottom = first;
	first->next = NULL;
}

/*
** rr: Rotates both stacks a and b
** a: First stack to rotate
** b: Second stack to rotate
** Prints "rr\n" to stdout
*/
void	rr(t_stack *a, t_stack *b)
{
	int	r_a;
	int	r_b;

	r_a = 0;
	r_b = 0;
	if (a && a->top && a->top->next)
		r_a = 1;
	if (b && b->top && b->top->next)
		r_b = 1;
	if (r_a && r_b)
	{
		ra_no_print(a);
		rb_no_print(b);
		write(1, "rr\n", 3);
		op_tracker("rr", 0);
	}
}
