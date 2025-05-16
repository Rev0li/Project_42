/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:51:14 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:51:14 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** ft_strlen *****/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
	{
		write(2, "Erreur : pointer NULL ft_strlen\n", 32);
		return (0);
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}
