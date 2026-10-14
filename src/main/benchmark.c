
#include "push_swap.h"

static void	update_ops_count(char *op, int ops[11])
{
	if (ft_strcmp(op, "sa") == 0)
		ops[0]++;
	else if (ft_strcmp(op, "sb") == 0)
		ops[1]++;
	else if (ft_strcmp(op, "ss") == 0)
		ops[2]++;
	else if (ft_strcmp(op, "pa") == 0)
		ops[3]++;
	else if (ft_strcmp(op, "pb") == 0)
		ops[4]++;
	else if (ft_strcmp(op, "ra") == 0)
		ops[5]++;
	else if (ft_strcmp(op, "rb") == 0)
		ops[6]++;
	else if (ft_strcmp(op, "rr") == 0)
		ops[7]++;
	else if (ft_strcmp(op, "rra") == 0)
		ops[8]++;
	else if (ft_strcmp(op, "rrb") == 0)
		ops[9]++;
	else if (ft_strcmp(op, "rrr") == 0)
		ops[10]++;
}

static void	print_ops_stats(int total, int ops[11])
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(ops[0], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops[1], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops[2], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops[3], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops[4], 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(ops[5], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops[6], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops[7], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops[8], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops[9], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops[10], 2);
	ft_putstr_fd("\n", 2);
}

void	op_tracker(char *op, int mode)
{
	static int	ops[11] = {0};
	static int	total = 0;
	int			i;

	if (mode == 1)
	{
		i = 0;
		while (i < 11)
			ops[i++] = 0;
		total = 0;
		return ;
	}
	if (mode == 0 && op)
	{
		total++;
		update_ops_count(op, ops);
	}
	else if (mode == 2)
		print_ops_stats(total, ops);
}

static void	print_strategy_info(int count, double disorder, t_options *opt)
{
	if (opt->strategy == STRAT_SIMPLE)
		ft_putstr_fd("[bench] strategy: simple / O(n^2) \n", 2);
	else if (opt->strategy == STRAT_MEDIUM)
		ft_putstr_fd("[bench] strategy: medium / O(n√n) \n", 2);
	else if (opt->strategy == STRAT_COMPLEX)
		ft_putstr_fd("[bench] strategy: complex / O(n log n) \n", 2);
	else
		print_adaptive_strategy(count, disorder);
}

void	print_benchmark(int count, double disorder, t_options *opt)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd((int)(disorder * 10000) % 100, 2);
	ft_putstr_fd("%\n", 2);
	print_strategy_info(count, disorder, opt);
	op_tracker(NULL, 2);
}
