/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:29:39 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:29:41 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sort_four: Sorts 4 numbers in stack a using stack b as auxiliary
** Algorithm:
** 1. Identify the smallest element among the 4 values
** 2. Determine its position (0-3, where 0 is top)
** 3. Rotate stack to bring smallest to top:
**    - Position 1: ra (second element becomes first)
**    - Position 2: rra twice (third element to top)
**    - Position 3: rra once (fourth element to top)
** 4. Push smallest to stack b (pb)
** 5. Sort remaining 3 elements in stack a (sort_three)
** 6. Push smallest back from b to a (pa)
** Time complexity: O(1) for fixed 4 elements
** Space complexity: O(1) auxiliary space
*/

static void	get_values(t_stack *a, int v[4])
{
	v[0] = a->top->value;
	v[1] = a->top->next->value;
	v[2] = a->top->next->next->value;
	v[3] = a->top->next->next->next->value;
}

static int	find_small(t_stack *a)
{
	int	v[4];
	int	smallest;
	int	pos;

	get_values(a, v);
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
	return (pos);
}

static void	do_rotations(t_stack *a, int pos)
{
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		rra(a);
		rra(a);
	}
	else if (pos == 3)
		rra(a);
}

static int	has_at_least_4(t_stack *a)
{
	return (a && a->top && a->top->next && a->top->next->next
		&& a->top->next->next->next);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	pos;

	if (!has_at_least_4(a))
		return ;
	pos = find_small(a);
	do_rotations(a, pos);
	push_b(a, b);
	sort_three(a);
	push_a(a, b);
}
