/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:27:31 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:27:32 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int count)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = count - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	radix_loop(t_stack *a, t_stack *b, int bit, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((a->top->index >> bit) & 1) == 0)
			push_b(a, b);
		else
			ra(a);
		j++;
	}
}

static int	set_index(t_stack *a, int *arr, int count)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * count);
	if (!sorted)
		return (0);
	ft_memcpy(sorted, arr, sizeof(int) * count);
	bubble_sort_array(sorted, count);
	assign_indexes(a, sorted, count);
	free(sorted);
	return (1);
}

void	complex_sort(t_stack *a, t_stack *b, int *arr, int count)
{
	int	i;
	int	max_bits;

	if (!set_index(a, arr, count))
		return ;
	max_bits = get_max_bits(count);
	i = 0;
	while (i < max_bits)
	{
		radix_loop(a, b, i, a->size);
		while (b->size > 0)
			push_a(a, b);
		i++;
	}
}
