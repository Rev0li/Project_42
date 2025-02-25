/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:18:30 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:05:28 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ult_lib.h"

/***** ft_strlcpy *****/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src)
	{
		write(2, "Erreur : pointeur NULL passé à ft_strlcpy\n", 44);
		return (-1);
	}
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
