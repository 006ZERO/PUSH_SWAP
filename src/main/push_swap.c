/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:51:29 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:51:30 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_adaptive(t_stack *a, t_stack *b, int *arr, double dis)
{
	int	count;

	count = a->size;
	if (count == 2 && a->top->value > a->top->next->value)
		swap_a(a);
	else if (count == 3)
		sort_three(a);
	else if (count == 4)
		sort_four(a, b);
	else if (count == 5)
		sort_five(a, b);
	else if (dis < 0.2)
		insertion_sort(a, b);
	else if (dis < 0.5)
		medium_sort(a, b, arr, count);
	else
		complex_sort(a, b, arr, count);
}

static void	run_mode(t_options *opt, t_stack *a, t_stack *b, int *arr)
{
	int		count;
	double	dis;

	count = a->size;
	dis = compute_disorder(arr, count);
	op_tracker(NULL, 1);
	if (!is_sorted(a))
	{
		if (opt->strategy == STRAT_SIMPLE)
			insertion_sort(a, b);
		else if (opt->strategy == STRAT_MEDIUM)
			medium_sort(a, b, arr, count);
		else if (opt->strategy == STRAT_COMPLEX)
			complex_sort(a, b, arr, count);
		else
			run_adaptive(a, b, arr, dis);
	}
	if (opt->bench)
		print_benchmark(count, dis, opt);
}

static void	free_all(t_options *opt, int *arr, t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (arr)
		free(arr);
	if (opt)
		free(opt);
}

static int	init_all(int argc, char **argv, t_options **opt, int **arr)
{
	int	count;

	*arr = NULL;
	*opt = parse_options(&argc, &argv);
	if (!*opt || argc < 2)
		return (0);
	*arr = parse_arguments(argc, argv, &count);
	if (!*arr)
		return (-1);
	return (count);
}

int	main(int argc, char **argv)
{
	t_options	*opt;
	t_stack		*a;
	t_stack		*b;
	int			*arr;
	int			count;

	a = NULL;
	b = NULL;
	arr = NULL;
	opt = NULL;
	count = init_all(argc, argv, &opt, &arr);
	if (count == 0)
		return (free_all(opt, NULL, NULL, NULL), 0);
	if (count == -1)
		return (ft_putstr_fd("Error\n", 2), free_all(opt, NULL, NULL, NULL), 1);
	a = create_stack_from_array(arr, count, 'a');
	b = create_empty_stack('b');
	if (!a || !b)
		return (ft_putstr_fd("Error\n", 2), free_all(opt, arr, a, b), 1);
	run_mode(opt, a, b, arr);
	free_all(opt, arr, a, b);
	return (0);
}
