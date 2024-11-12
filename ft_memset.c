/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:18:17 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/12 08:38:17 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *startAddr, int copie, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = startAddr;
	i = 0;
	while (i < n)
	{
		s[i] = (unsigned char)copie;
		i++;
	}
	return (startAddr);
}
