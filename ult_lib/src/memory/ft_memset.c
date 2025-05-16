/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:42:48 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:42:48 by okientzl         ###   ########.fr       */
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
