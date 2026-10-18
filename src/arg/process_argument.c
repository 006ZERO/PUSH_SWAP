/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:49:14 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/16 13:50:34 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** check_duplicates: Checks if there are duplicate numbers in the array
** numbers: Array of integers to check
** count: Number of elements in the array
** Returns: 1 if no duplicates, 0 if duplicates found
*/
static int	check_duplicates(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
** convert_and_allocate: Converts string tokens to integers and allocates array
** tokens: Array of strings to convert
** count: Number of tokens to convert
** Returns: Allocated array of integers, or NULL on error
*/
static int	*convert_and_allocate(char **tokens, int count)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (!string_argument(tokens[i], &numbers[i]))
		{
			free(numbers);
			return (NULL);
		}
		i++;
	}
	return (numbers);
}

/*
** cleanup: Frees memory allocated by ft_split if needed
** tokens: Array of strings to free
** argc: Argument count to determine if ft_split was used
*/
static void	cleanup(char **tokens, int argc)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
}

/*
** parse_arguments: Main function to parse command line arguments
** Handles two input formats:
**   1. Multiple arguments: ./push_swap 4 67 3 12 9
**   2. Single string: ./push_swap "4 67 3 12 9"
** argc: Argument count
** argv: Argument vector
** count: Pointer to store number of parsed integers
** Returns: Array of integers, or NULL on error
*/
int	*parse_arguments(int argc, char **argv, int *count)
{
	char	**tokens;
	int		*numbers;

	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else
		tokens = &argv[1];
	if (!tokens)
		return (NULL);
	*count = 0;
	while (tokens[*count])
		(*count)++;
	numbers = NULL;
	if (*count > 0)
		numbers = convert_and_allocate(tokens, *count);
	if (numbers && !check_duplicates(numbers, *count))
	{
		free(numbers);
		numbers = NULL;
	}
	cleanup(tokens, argc);
	return (numbers);
}
