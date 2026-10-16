/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:27:42 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:43:37 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	move_to_top_stack(t_stack *s, int index, char stack_name)
{
	if (index <= s->size / 2)
	{
		while (index > 0)
		{
			if (stack_name == 'a')
				ra(s);
			else
				rb(s);
			index--;
		}
	}
	else
	{
		index = s->size - index;
		while (index > 0)
		{
			if (stack_name == 'a')
				rra(s);
			else
				rrb(s);
			index--;
		}
	}
}

static void	scan_chunk(t_stack *a, int start, int end, int pos[2])
{
	t_node	*cur;
	int		i;

	pos[0] = -1;
	pos[1] = -1;
	cur = a->top;
	i = 0;
	while (cur)
	{
		if (cur->index >= start && cur->index <= end)
		{
			if (pos[0] == -1)
				pos[0] = i;
			pos[1] = i;
		}
		cur = cur->next;
		i++;
	}
}

int	find_best_chunk_pos(t_stack *a, int start, int end)
{
	int	pos[2];

	if (!a || !a->top)
		return (-1);
	scan_chunk(a, start, end, pos);
	if (pos[0] == -1)
		return (-1);
	if ((a->size - pos[1]) < pos[0])
		return (pos[1]);
	return (pos[0]);
}

int	find_max_index_pos(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		max_pos;
	int		pos;

	if (!b || !b->top)
		return (-1);
	cur = b->top;
	max = cur->index;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}
