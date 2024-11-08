/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:31:41 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 18:23:13 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	len = strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));

	if (!copy)
		return NULL;
	for (size_t i = 0; i <= len; i++)
		copy[i] = s[i];
	return copy;
}
