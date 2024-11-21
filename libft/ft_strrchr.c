/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:15:04 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 15:31:56 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_occurrence = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	    char str1[] = "Hello, World!";
//     char *result1 = ft_strrchr(str1, 'W');
//     char *expected1 = strrchr(str1, 'W');
//     if (result1 == expected1)
//         printf("Caractère présent une fois | [SUCCÈS]\n");
//     else
//         printf("Caractère présent une fois | [ÉCHOUÉ]\n");
//
//     char str2[] = "banana";
//     char *result2 = ft_strrchr(str2, 'a');
//     char *expected2 = strrchr(str2, 'a');
//     if (result2 == expected2)
//         printf("Caractère présent plusieurs fois | [SUCCÈS]\n");
//     else
//         printf("Caractère présent plusieurs fois | [ÉCHOUÉ]\n");
//
//     char str3[] = "apple";
//     char *result3 = ft_strrchr(str3, 'z');
//     char *expected3 = strrchr(str3, 'z');
//     if (result3 == expected3)
//         printf("Caractère non présent | [SUCCÈS]\n");
//     else
//         printf("Caractère non présent | [ÉCHOUÉ]\n");
//
//     char str4[] = "test";
//     char *result4 = ft_strrchr(str4, '\0');
//     char *expected4 = strrchr(str4, '\0');
//     if (result4 == expected4)
//         printf("Recherche du caractère '\\0' | [SUCCÈS]\n");
//     else
//         printf("Recherche du caractère '\\0' | [ÉCHOUÉ]\n");
//
//     char str5[] = "";
//     char *result5 = ft_strrchr(str5, 'a');
//     char *expected5 = strrchr(str5, 'a');
//     if (result5 == expected5)
//         printf("Chaîne vide | [SUCCÈS]\n");
//     else
//         printf("Chaîne vide | [ÉCHOUÉ]\n");
// }
