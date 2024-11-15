/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:38:14 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 13:28:09 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char data[] = "42Network";
//
// 	if (ft_memchr(data, 'N', 9) == memchr(data, 'N', 9))
// 		printf("\nCaractere 'N' [SUCCES]\n");
// 	else
// 		printf("\nCaractere 'N' [FAIL]\n");
//
// 	if (ft_memchr(data, 'X', 9) == memchr(data, 'X', 9))
// 		printf("\nCaractère non présent ('X') [SUCCES]\n");
// 	else
// 		printf("\nCaractère non présent ('X') [FAIL]\n");
//
// 	if (ft_memchr(data, '\0', 10) == memchr(data, '\0', 10))
// 		printf("\nRecherche du caractère nul [SUCCES]\n");
// 	else
// 		printf("\nRecherche du caractère nul [FAIL]\n");
//
// 	if (ft_memchr(data, '4', 0) == memchr(data, '4', 0))
// 		printf("\nTaille de recherche 0 [SUCCES]\n");
// 	else
// 		printf("\nTaille de recherche 0 [FAIL]\n");
// }
