/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:04:46 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 16:46:29 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	const char *str1 = "Hello, world!";
// 	if (ft_strchr(str1, 'H') == strchr(str1, 'H'))
// 		printf("Caractère présent au début [SUCCES]\n");
// 	else
// 		printf("Caractère présent au début [FAIL]");
//
// 	if (ft_strchr(str1, 'o') == strchr(str1, 'o'))
// 		printf("Caractère présent au milieu [SUCCES]\n");
// 	else
// 		printf("Caractère présent au milieu [FAIL]");
//
// 	if (ft_strchr(str1, '!') == strchr(str1, '!'))
// 		printf("Caractère présent à la fin [SUCCES]\n");
// 	else
// 		printf("Caractère présent à la fin [FAIL]");
//
// 	if (ft_strchr(str1, 'x') == strchr(str1, 'x'))
// 		printf("Caractère non présent [SUCCES]\n");
// 	else
// 		printf("Caractère non présent [FAIL]");
//
// 	if (ft_strchr(str1, '\0') == strchr(str1, '\0'))
// 		printf("Caractère nul '\\0' [SUCCES]\n");
// 	else
// 		printf("Caractère nul '\\0' [FAIL]");
//
// 	const char *empty_str = "";
// 	if (ft_strchr(empty_str, 'a') == strchr(empty_str, 'a'))
// 		printf("Chaîne vide [SUCCES]\n");
// 	else
// 		printf("Chaîne vide [FAIL]");
// }
