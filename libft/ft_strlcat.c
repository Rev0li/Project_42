/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:19:10 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 14:27:26 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	i = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] != '\0' && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
// #include <bsd/string.h>
// #include <stdio.h>
// int	main()
// {
//     char src[] = " World!";
//
//     char dest1[20] = "Hello";
//     char dest2[20] = "Hello";
//     size_t result1 = ft_strlcat(dest1, src, sizeof(dest1));
//     size_t result2 = strlcat(dest2, src, sizeof(dest2));
//     if (strcmp(dest1, dest2) == 0 && result1 == result2)
//         printf("Concaténation simple [SUCCES]\n");
//     else
//         printf("Concaténation simple [ÉCHOUÉ]");
//
//     char dest_small1[10] = "Hello";
//     char dest_small2[10] = "Hello";
//     result1 = ft_strlcat(dest_small1, src, sizeof(dest_small1));
//     result2 = strlcat(dest_small2, src, sizeof(dest_small2));
//     if (strcmp(dest_small1, dest_small2) == 0 && result1 == result2)
//         printf("Destination trop petite [SUCCES]\n");
//     else
//         printf("Destination trop petite [ÉCHOUÉ]");
//
//     char dest_zero1[20] = "Initial";
//     char dest_zero2[20] = "Initial";
//     result1 = ft_strlcat(dest_zero1, src, 0);
//     result2 = strlcat(dest_zero2, src, 0);
//     if (strcmp(dest_zero1, dest_zero2) == 0 && result1 == result2)
//         printf("Taille destination 0 [SUCCES]\n");
//     else
//         printf("Taille destination 0 [ÉCHOUÉ]");
//
//     char dest_empty1[20] = "Hello";
//     char dest_empty2[20] = "Hello";
//     char src_empty[] = "";
//     result1 = ft_strlcat(dest_empty1, src_empty, sizeof(dest_empty1));
//     result2 = strlcat(dest_empty2, src_empty, sizeof(dest_empty2));
//     if (strcmp(dest_empty1, dest_empty2) == 0 && result1 == result2)
//         printf("Source vide [SUCCES]\n");
//     else
//         printf("Source vide [ÉCHOUÉ]");
//
// }
