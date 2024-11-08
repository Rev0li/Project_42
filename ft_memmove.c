/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:18:06 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 15:09:28 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	if (d == s || n == 0) // Nothing to do if source and destination are the same or size is 0
		return dest;

	if (d < s)
	{
		// Forward copy (similar to memcpy)
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		// Backward copy to handle overlap correctly
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}

	return dest;
}

