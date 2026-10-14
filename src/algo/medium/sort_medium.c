#include "push_swap.h"

void	assign_indexes(t_stack *a, int *sorted, int count)
{
	int		i;
	int		found;
	t_node	*cur;

	if (!a || !a->top || !sorted)
		return ;
	cur = a->top;
	while (cur)
	{
		i = 0;
		found = 0;
		while (i < count && !found)
		{
			if (cur->value == sorted[i])
			{
				cur->index = i;
				found = 1;
			}
			i++;
		}
		cur = cur->next;
	}
}

static void	handle_element_in_chunk(t_stack *a, t_stack *b,
									int start, int chunk)
{
	int	pos;

	pos = find_best_chunk_pos(a, start, start + chunk - 1);
	if (pos == -1)
		return ;
	move_to_top_stack(a, pos, 'a');
	push_b(a, b);
	if (b->top->index < start + (chunk / 2))
		rb(b);
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = find_max_index_pos(b);
		if (max_pos < 0)
			return ;
		move_to_top_stack(b, max_pos, 'b');
		push_a(a, b);
	}
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, int count, int chunk)
{
	int	start;
	int	end;

	start = 0;
	end = chunk - 1;
	if (end >= count)
		end = count - 1;
	while (a->size > 0 && start < count)
	{
		if (find_best_chunk_pos(a, start, end) != -1)
			handle_element_in_chunk(a, b, start, chunk);
		else
		{
			start = end + 1;
			end = start + chunk - 1;
			if (end >= count)
				end = count - 1;
		}
	}
}

void	medium_sort(t_stack *a, t_stack *b, int *original, int count)
{
	int	chunk;
	int	*sorted;

	sorted = malloc(sizeof(int) * count);
	if (!sorted)
		return ;
	ft_memcpy(sorted, original, sizeof(int) * count);
	bubble_sort_array(sorted, count);
	assign_indexes(a, sorted, count);
	if (count <= 10)
		chunk = 3;
	else if (count <= 100)
		chunk = 15;
	else
		chunk = 32;
	push_chunks_to_b(a, b, count, chunk);
	push_back_to_a(a, b);
	free(sorted);
}
