/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:51:24 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:51:25 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_option(t_options *opt, char *arg)
{
	if (ft_strcmp(arg, "--bench") == 0)
		opt->bench = 1;
	else if (ft_strcmp(arg, "--simple") == 0)
		opt->strategy = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		opt->strategy = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		opt->strategy = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		opt->strategy = STRAT_ADAPTIVE;
	else
	{
		ft_putstr_fd("Error\n", 2);
		free(opt);
		exit(1);
	}
}

static void	parse_flags(t_options *opt, int *argc, char ***argv)
{
	int	i;

	i = 1;
	while (i < *argc && (*argv)[i][0] == '-' && (*argv)[i][1] == '-')
	{
		handle_option(opt, (*argv)[i]);
		i++;
	}
	*argv += (i - 1);
	*argc -= (i - 1);
}

t_options	*parse_options(int *argc, char ***argv)
{
	t_options	*opt;

	opt = malloc(sizeof(t_options));
	if (!opt)
		return (NULL);
	opt->bench = 0;
	opt->strategy = STRAT_ADAPTIVE;
	if (*argc > 1 && (*argv)[1][0] == '-' && (*argv)[1][1] == '-')
		parse_flags(opt, argc, argv);
	return (opt);
}

void	print_adaptive_strategy(int count, double disorder)
{
	if (count == 2 || count == 3 || count == 4 || count == 5)
		ft_putstr_fd("[bench] strategy: Adaptive / O(1)\n", 2);
	else if (disorder < 0.2)
		ft_putstr_fd("[bench] strategy: Adaptive / O(n^2)\n", 2);
	else if (disorder < 0.5)
		ft_putstr_fd("[bench] strategy: Adaptive / O(n√n)\n", 2);
	else
		ft_putstr_fd("[bench] strategy: Adaptive / O(n log n)\n", 2);
}

int	count_only_mode(int set, int value)
{
	static int	mode = 0;

	if (set)
		mode = value;
	return (mode);
}
