/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:19:58 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 13:14:03 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>
// #include <string.h>
// void to_uppercase(unsigned int index, char *c)
// {
// 	(void)index;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c -= 32;
// }
// void add_index(unsigned int index, char *c)
// {
// 	*c += index;
// }
// int	main()
// {
// 	char str1[] = "hello";
// 	char str2[] = "abcd";
// 	char str3[] = "";
// 	ft_striteri(str1, to_uppercase);
// 	if (strcmp(str1, "HELLO") == 0)
// 		printf("| %-20s | [SUCCÈS]|\n", "to_uppercase");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "to_uppercase", str1);
//
// 	ft_striteri(str2, add_index);
// 	if (strcmp(str2, "aceg") == 0)
// 		printf("| %-20s | [SUCCÈS]|\n", "add_index");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "add_index", str2);
//
// 	ft_striteri(str3, to_uppercase);
// 	if (strcmp(str3, "") == 0)
// 		printf("| %-20s | [SUCCÈS]|\n", "empty string");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "empty string", str3);
//
// }
