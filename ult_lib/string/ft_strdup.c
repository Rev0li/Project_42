/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:28:14 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:05:34 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ult_lib.h"

/***** strdup *****/
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	if (!s)
	{
		write(2, "Erreur : pointeur NULL passé à ft_strdup\n", 43);
		return (NULL);
	}
	len = ft_strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
	{
		write(2, "Erreur : échec de l'allocation mémoire dans ft_strdup\n", 56);
		return (NULL);
	}
	ft_memcpy(copy, s, len);
	copy[len] = '\0';
	return (copy);
}

