/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:16:16 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 15:32:13 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	i = 0;
	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i] || s1[i] == '\0' || s2[i] == '\0')
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>
//
// int	main()
// {
//     char str1[] = "Hello";
//     char str2[] = "Hello";
//     int result1 = ft_strncmp(str1, str2, 5);
//     int expected1 = strncmp(str1, str2, 5);
//     if (result1 == expected1)
//         printf("Chaînes identiques | [SUCCES]\n");
//     else
//         printf("Chaînes identiques | [ÉCHOUÉ]\n");
//
//     char str3[] = "Hello";
//     char str4[] = "World";
//     int result2 = ft_strncmp(str3, str4, 5);
//     int expected2 = strncmp(str3, str4, 5);
//     if (result2 == expected2)
//         printf("Chaînes différentes | [SUCCES]\n");
//     else
//         printf("Chaînes différentes | [ÉCHOUÉ]\n");
//
//     char str5[] = "abcdef";
//     char str6[] = "abcxyz";
//     int result3 = ft_strncmp(str5, str6, 3);
//     int expected3 = strncmp(str5, str6, 3);
//     if (result3 == expected3)
//         printf("Comparaison partielle (n=3) | [SUCCES]\n");
//     else
//         printf("Comparaison partielle (n=3) | [ÉCHOUÉ]\n");
//
//     char str7[] = "";
//     char str8[] = "Non-vide";
//     int result4 = ft_strncmp(str7, str8, 5);
//     int expected4 = strncmp(str7, str8, 5);
//     if (result4 == expected4)
//         printf("Comparaison avec une chaîne vide | [SUCCES]\n");
//     else
//         printf("Comparaison avec une chaîne vide | [ÉCHOUÉ]\n");
//
//     char str9[] = "Hello";
//     char str10[] = "World";
//     int result5 = ft_strncmp(str9, str10, 0);
//     int expected5 = strncmp(str9, str10, 0);
//     if (result5 == expected5)
//         printf("Comparaison avec n=0 | [SUCCES]\n");
//     else
//         printf("Comparaison avec n=0 | [ÉCHOUÉ]\n");
// }
