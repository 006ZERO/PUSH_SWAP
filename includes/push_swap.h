/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:26:48 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:26:51 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	char	name;
}	t_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE = 0,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_options
{
	int			bench;
	t_strategy	strategy;
}	t_options;

/* Options */
t_options	*parse_options(int *argc, char ***argv);
int			count_only_mode(int set, int value);

/* Arguments & String Utils */
int			ft_strcmp(const char *s1, const char *s2);
int			string_argument(const char *str, int *out);
int			*parse_arguments(int argc, char **argv, int *count);

/* Stack Utils */
t_node		*create_node(int value);
t_stack		*create_empty_stack(char name);
t_stack		*create_stack_from_array(int *arr, int count, char name);
void		free_stack(t_stack *stack);

/* Operations */
void		swap_a(t_stack *a);
void		swap_b(t_stack *b);
void		swap_ss(t_stack *a, t_stack *b);
void		swap_a_no_print(t_stack *a);
void		swap_b_no_print(t_stack *b);

void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);

void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		ra_no_print(t_stack *a);
void		rb_no_print(t_stack *b);

void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		rra_no_print(t_stack *a);
void		rrb_no_print(t_stack *b);

/* Simple Sort */
void		sort_three(t_stack *a);
void		sort_four(t_stack *a, t_stack *b);
void		sort_five(t_stack *a, t_stack *b);
int			is_sorted(t_stack *a);
void		insertion_sort(t_stack *a, t_stack *b);

/* Medium Sort */
void		bubble_sort_array(int *arr, int n);
void		move_to_top_stack(t_stack *s, int index, char stack_name);
int			find_best_chunk_pos(t_stack *a, int start, int end);
int			find_max_index_pos(t_stack *b);
void		medium_sort(t_stack *a, t_stack *b, int *original, int count);
void		assign_indexes(t_stack *a, int *sorted, int count);

/* Complex Sort */
void		complex_sort(t_stack *a, t_stack *b, int *arr, int count);

/* Disorder & Benchmark */
double		compute_disorder(int *arr, int n);
void		op_tracker(char *op, int mode);
void		print_benchmark(int count, double disorder, t_options *opt);
void		print_adaptive_strategy(int count, double disorder);

#endif
