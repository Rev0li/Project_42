/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:42:12 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 15:02:29 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*p1;
	const unsigned char		*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
//     char *s1 = "Hello";
//     char *s2 = "Hello";
//     char *s3 = "Jello";
//     char *s4 = "HelloWorld";
//     char *s5 = "";
//     char *s6 = "";
//
// 	if (ft_memcmp("Hello", "Hello", 5) == memcmp("Hello", "Hello", 5))
// 		printf("\nDeux chaînes identiques [SUCCES]");
// 	else
// 		printf("\nDeux chaînes identiques [FAIL]");
//
// 	if (ft_memcmp("Hello", s3, 5) == memcmp("Hello", s3, 5))
// 		printf("\nChaînes différentes (premier caractère) [SUCCES]");
// 	else
// 		printf("\nChaînes différentes (premier caractère) [FAIL]");
//
// 	if (ft_memcmp("Hello", s2, 1) == memcmp("Hello", s2, 1))
// 		printf("\nComparaison partielle [SUCCES]");
// 	else
// 		printf("\nComparaison partielle [FAIL]");
//
// 	if (ft_memcmp("Hello", "HelloWorld", 5) == memcmp("Hello", "HelloWord", 5))
// 		printf("\nMême préfixe, longueurs différentes [SUCCES]");
// 	else
// 		printf("\nMême préfixe, longueurs différentes [FAIL]");
//
// 	if (ft_memcmp("", "", 0) == memcmp("", "", 0))
// 		printf("\nDeux chaînes identiques [SUCCES]");
// 	else
// 		printf("\nDeux chaînes identiques [FAIL]");
// }
