/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:09:38 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 17:10:11 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** memset *****/
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
