#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a || !a->top)
		return (1);
	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static int	find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		min_pos;
	int		pos;

	if (!a || !a->top)
		return (-1);
	cur = a->top;
	min = cur->value;
	min_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		pos = a->size - pos;
		while (pos > 0)
		{
			rra(a);
			pos--;
		}
	}
}

void	insertion_sort(t_stack *a, t_stack *b)
{
	int	pos;

	if (!a || is_sorted(a))
		return ;
	while (a->size > 0 && !is_sorted(a))
	{
		pos = find_min_pos(a);
		move_min_to_top(a, pos);
		push_b(a, b);
	}
	while (b->size > 0)
		push_a(a, b);
}
