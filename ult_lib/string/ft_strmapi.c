/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:36:05 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:05:31 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ult_lib.h"

/***** strmapi *****/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
	{
		write(2, "Erreur : pointeur NULL passé à ft_strmapi\n", 44);
		return (NULL);
	}
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
	{
		write(2, "Erreur : échec de l'allocation mémoire dans ft_strmapi\n", 57);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
