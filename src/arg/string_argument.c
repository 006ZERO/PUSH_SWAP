
#include "push_swap.h"
#include <limits.h>

/*
** check_overflow: Checks if the number exceeds INT_MAX or INT_MIN
** sum: Current number being built
** sig: Sign (1 for positive, -1 for negative)
** Returns: 1 if valid, 0 if overflow
*/
static int	check_overflow(unsigned long long sum, int sig)
{
	if (sig == 1 && sum > (unsigned long long)INT_MAX)
		return (0);
	if (sig == -1 && sum > (unsigned long long)INT_MAX + 1ULL)
		return (0);
	return (1);
}

/*
** process_numbers: Converts string to integer with overflow checking
** str: Input string
** x: Starting index in string
** out: Pointer to store result
** sig: Sign of the number
** Returns: 1 if successful, 0 if error
*/
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

/*
** string_argument: Converts string to integer with validation
** str: Input string to convert
** out: Pointer to store converted integer
** Returns: 1 if successful, 0 if error
*/
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
