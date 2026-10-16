/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:26:36 by gabusalm          #+#    #+#             */
/*   Updated: 2026/09/30 22:32:33 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lensub;
	size_t	i;
	size_t	copylen;
	char	*substr;

	lensub = ft_strlen(s);
	if (start >= lensub)
		copylen = 0;
	else if (len < lensub - start)
		copylen = len;
	else
		copylen = lensub - start;
	substr = malloc(copylen + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < copylen)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
