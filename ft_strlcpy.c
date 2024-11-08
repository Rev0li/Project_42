/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:19:30 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 12:19:35 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i = 0;

	// Calculate the length of src
	while (src[i] != '\0')
		i++;

	// If size is 0, nothing is copied and we return the length of src
	if (size == 0)
		return i;

	size_t j = 0;
	while (j < size - 1 && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}

	// Null-terminate dst
	if (size > 0)
		dst[j] = '\0';

	return i; // Return length of src
}

