/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:31:41 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/12 08:20:18 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*copy;

	i = 0;
	len = ft_strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (i <= len)
	{
		copy[i] = s[i];
		i++;
	}
	return (copy);
}
