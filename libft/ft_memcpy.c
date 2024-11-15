/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:17:57 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 15:22:35 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (0);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
//
// 	char src[] = "Hello, World!";
// 	char dest[20] = {0};
//
// 	ft_memcpy(dest, src, 13);
// 	if (strcmp(dest, src) == 0)
// 		printf("Test basique (chaine) [SUCCES]\n");
// 	else
// 		printf("Test basique (chaine) [ÉCHOUÉ]\n");
//
// 	char dest_zero[20] = {0};
// 	ft_memcpy(dest_zero, src, 0);
// 	if (dest_zero[0] == '\0')
// 		printf("Test 0 octets [SUCCES]\n");
// 	else
// 		printf("Test 0 octets [FAIL]\n");
//
// 	int src_int[] = {1, 2, 3, 4, 5};
// 	int dest_int[5] = {0};
// 	ft_memcpy(dest_int, src_int, 5 * sizeof(int));
// 	int i = 0;
// 	int success = 1;
// 	while (i < 5)
// 	{
// 		if (dest_int[i] != src_int[i])
// 		{
// 			success = 0;
// 			break;
// 		}
// 		i++;
// 	}
// 	    if (success)
//         printf("Tableau d'int [SUCCES]\n");
//     else
//         printf("Tableau d'int [FAIL]\n");
// }
