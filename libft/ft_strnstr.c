/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:13:19 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/18 11:28:21 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (!needle[j + 1])
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <bsd/string.h>
//
// int	main()
// {    
// 	const char haystack1[] = "Hello, World!";
//     const char needle1[] = "World";
//     char *result1 = ft_strnstr(haystack1, needle1, 13);
//     if (result1 != NULL && strcmp(result1, "World!") == 0)
//         printf("Recherche sous-chaîne présente | [SUCCES]\n");
//     else
//         printf("Recherche sous-chaîne présente | [ÉCHOUÉ]\n");
//
//     const char needle2[] = "42";
//     char *result2 = ft_strnstr(haystack1, needle2, 13);
//     if (result2 == NULL)
//         printf("Recherche sous-chaîne absente | [SUCCES]\n");
//     else
//         printf("Recherche sous-chaîne absente | [ÉCHOUÉ]\n");
//
//     char *result3 = ft_strnstr(haystack1, needle1, 5);
//     if (result3 == NULL)
//         printf("Recherche limitée trop courte | [SUCCES]\n");
//     else
//         printf("Recherche limitée trop courte | [ÉCHOUÉ]\n");
//
//     char *result4 = ft_strnstr(haystack1, "", 13);
//     if (result4 == haystack1)
//         printf("Recherche chaîne vide | [SUCCES]\n");
//     else
//         printf("Recherche chaîne vide | [ÉCHOUÉ]\n");
//
//     char *result5 = ft_strnstr(haystack1, needle1, 0);
//     if (result5 == NULL)
//         printf("Recherche avec len = 0 | [SUCCES]\n");
//     else
//         printf("Recherche avec len = 0 | [ÉCHOUÉ]\n");
// }
