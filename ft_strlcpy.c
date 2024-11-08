/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:19:30 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 18:26:48 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	i = 0;

	while (src[i] != '\0')
		i++;

	if (size == 0)
		return i;

	size_t j = 0;
	while (j < size - 1 && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}

	if (size > 0)
		dst[j] = '\0';

	return i;
}

