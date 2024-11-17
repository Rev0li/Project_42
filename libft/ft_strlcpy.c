/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:19:30 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 14:34:11 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (j < size - 1 && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	if (size > 0)
		dst[j] = '\0';
	return (i);
}
// #include <string.h>
// #include <stdio.h>
// int	main()
// {
//     char src[] = "Hello, World!";
//     char dest[20] = {0};
//     size_t len = ft_strlcpy(dest, src, sizeof(dest));
//     if (strcmp(dest, src) == 0 && len == strlen(src))
//         printf("Copie d'une chaîne simple [SUCCES]\n");
//     else
//         printf("Copie d'une chaîne simple [ÉCHOUÉ]\n");
//
//     char dest_small[6] = {0};
//     len = ft_strlcpy(dest_small, src, sizeof(dest_small));
//     if (strcmp(dest_small, "Hello") == 0 && len == strlen(src))
//         printf("Destination trop petite [SUCCES]\n");
//     else
//         printf("Destination trop petite [ÉCHOUÉ]\n");
//
//     char dest_zero[20] = "Initial";
//     len = ft_strlcpy(dest_zero, src, 0);
//     if (strcmp(dest_zero, "Initial") == 0 && len == strlen(src))
//         printf("Taille destination 0 [SUCCES]\n");
//     else
//         printf("Taille destination 0 [ÉCHOUÉ]\n");
//
//     char src_empty[] = "";
//     char dest_empty[10] = {0};
//     len = ft_strlcpy(dest_empty, src_empty, sizeof(dest_empty));
//     if (strcmp(dest_empty, "") == 0 && len == 0)
//         printf("Source vide [SUCCES]\n");
//     else
//         printf("Source vide [ÉCHOUÉ]\n");
//
// }
