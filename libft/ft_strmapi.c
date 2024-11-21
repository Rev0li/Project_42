/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:57:14 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 15:32:45 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
// #include <stdio.h>
// #include <string.h>
// int	ft_strlen(const char *string)
// {
// 	int	i;
//
// 	i = 0;
// 	while (string[i] != '\0')
// 		i++;
// 	return (i);
// }
//
// char example_func(unsigned int index, char c)
// {
//     return (c + index);
// }
// int	main()
// {
// 	char *result;
// 	char expected[50];
//
// 	result = ft_strmapi("abcd", example_func);
// 	snprintf(expected, sizeof(expected), "%s", "aceg");
// 	if (result && strcmp(result, expected) == 0)
// 		printf("| %-20s | [SUCCÈS] |\n", "transform basic");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] Résultat: %s|\n","transform basic",result);
// 	free(result);
//
// 	result = ft_strmapi("", example_func);
// 	snprintf(expected, sizeof(expected), "%s", "");
// 	if (result && strcmp(result, expected) == 0)
// 		printf("| %-20s | [SUCCÈS] |\n", "empty string");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] Résultat: %s|\n","empty string",result);
// 	free(result);
//
// 	result = ft_strmapi(NULL, example_func);
// 	if (result == NULL)
// 		printf("| %-20s | [SUCCÈS] |\n", "NULL input");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] Résultat: %s  |\n", "NULL input", result);
// }
