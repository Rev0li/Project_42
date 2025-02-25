//* ************************************************************************** */
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

/***** ft_strlen *****/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
	{
		write(2, "Erreur : pointeur NULL passé à ft_strlen\n", 43);
		return (0);
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}
