/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:18:17 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 15:58:06 by okientzl         ###   ########.fr       */
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
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
//
// 	char buf1[64];
// 	char buf2[64];
//
// 	ft_memset(buf1, 42, 64);
// 	memset(buf2, 42, 64);
//
// 	if(memcmp(buf1, buf2, 64) == 0)
// 	{
// 		printf("Remplissage total  [SUCCES]\n");
// 	}
// 	else
// 		printf("Remplissage total   [FAIL]\n");
//
// 	ft_memset(buf1, 42, 30);
// 	memset(buf1, 42, 30);
//
// 	if(memcmp(buf1, buf2, 64) == 0)
// 	{
// 		printf("Remplissage partiel  [SUCCES]\n");
// 	}
// 	else
// 		printf("Remplissage partiel   [FAIL]\n");
// }
