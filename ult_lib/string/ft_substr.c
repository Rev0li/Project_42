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

/***** substr *****/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;

	if (!s)
	{
		write("Erreur : pointeur NULL passé à ft_substr\n", 43);
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
	{
		write(2, "Erreur : échec de l'allocation mémoire dans ft_substr\n", 56);
		return (NULL);
	}
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}
