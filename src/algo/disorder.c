/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:27:18 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:27:24 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	compute_disorder(int *arr, int n)
{
	long long	mistakes;
	long long	total;
	int			i;
	int			j;

	if (n < 2)
		return (0.0);
	mistakes = 0;
	total = 0;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			total++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total);
}
