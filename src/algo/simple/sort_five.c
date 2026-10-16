/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:28:46 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:28:48 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_five(t_stack *a)
{
	return (a && a->top && a->top->next && a->top->next->next
		&& a->top->next->next->next && a->top->next->next->next->next);
}

static void	get_five_values(t_stack *a, int v[5])
{
	v[0] = a->top->value;
	v[1] = a->top->next->value;
	v[2] = a->top->next->next->value;
	v[3] = a->top->next->next->next->value;
	v[4] = a->top->next->next->next->next->value;
}

static int	find_small_pos_five(t_stack *a)
{
	int	v[5];
	int	smallest;
	int	pos;

	get_five_values(a, v);
	smallest = v[0];
	pos = 0;
	if (v[1] < smallest)
	{
		smallest = v[1];
		pos = 1;
	}
	if (v[2] < smallest)
	{
		smallest = v[2];
		pos = 2;
	}
	if (v[3] < smallest)
	{
		smallest = v[3];
		pos = 3;
	}
	if (v[4] < smallest)
		pos = 4;
	return (pos);
}

static void	do_rotations_five(t_stack *a, int pos)
{
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
	{
		rra(a);
		rra(a);
	}
	else if (pos == 4)
		rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	pos;

	if (!has_five(a))
		return ;
	pos = find_small_pos_five(a);
	do_rotations_five(a, pos);
	push_b(a, b);
	sort_four(a, b);
	push_a(a, b);
}
