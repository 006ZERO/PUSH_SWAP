/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:49:32 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:49:33 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	check_overflow(unsigned long long sum, int sig)
{
	if (sig == 1 && sum > (unsigned long long)INT_MAX)
		return (0);
	if (sig == -1 && sum > (unsigned long long)INT_MAX + 1ULL)
		return (0);
	return (1);
}

static int	process_numbers(const char *str, int x, int *out, int sig)
{
	unsigned long long	sum;

	sum = 0;
	while (str[x] >= '0' && str[x] <= '9')
	{
		sum = (sum * 10) + (str[x] - '0');
		if (!check_overflow(sum, sig))
			return (0);
		x++;
	}
	while (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] != '\0')
		return (0);
	if (sig == -1)
		*out = (int)(-(long long)sum);
	else
		*out = (int)sum;
	return (1);
}

int	string_argument(const char *str, int *out)
{
	int	x;
	int	sig;

	x = 0;
	sig = 1;
	while (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '\0')
		return (0);
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sig = -1;
		x++;
	}
	if (!(str[x] >= '0' && str[x] <= '9'))
		return (0);
	return (process_numbers(str, x, out, sig));
}
