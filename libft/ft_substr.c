/* ************************************************************************** */
/*                                                             */
/*                                         :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                     +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>     +#+  +:+       +#+        */
/*                                 +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:15:01 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 15:30:23 by okientzl         ###   ########.fr       */
/*                                                             */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		i;
	size_t		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		result[i] = s[start];
		start++;
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
// int	main()
// {
// 	char *result;
// 	char expected[20];
//
// 	result = ft_substr("hello world", 0, 5);
// 	snprintf(expected, sizeof(expected), "%s", "hello");
// 	if (result && strcmp(result, expected) == 0)
// 		printf("| [SUCCÈS] | hello \n");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] |\n", result);
// 	free(result);
//
// 	result = ft_substr("hello world", 0, 0);
// 	snprintf(expected, sizeof(expected), "%s", "");
// 	if (result && strcmp(result, expected) == 0)
// 		printf("| [SUCCÈS] | empty\n");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] |\n", result);
// 	free(result);
//
// 	result = ft_substr("hello world", 6, 5);
// 	snprintf(expected, sizeof(expected), "%s", "world");
// 	if (result && strcmp(result, expected) == 0)
// 		printf("| [SUCCÈS] | world\n");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] |\n", result);
// 	free(result);
//
// 	result = ft_substr("hello", 10, 5);
// 	snprintf(expected, sizeof(expected), "%s", "");
// 	if (result && strcmp(result, expected) == 0)
// 		printf("| [SUCCÈS] | empty\n");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] |\n", result);
// 	free(result);
//
// 	result = ft_substr("", 0, 5);
// 	snprintf(expected, sizeof(expected), "%s", "");
// 	if (result && strcmp(result, expected) == 0)
// 		printf("| [SUCCÈS] | empty\n");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] |\n", result);
// 	free(result);
//
// 	result = ft_substr("hello", 1, 10);
// 	snprintf(expected, sizeof(expected), "%s", "ello");
// 	if (result && strcmp(result, expected) == 0)
// 		printf("| [SUCCÈS] | ello\n");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] |\n", result);
// 	free(result);
//
// 	result = ft_substr(NULL, 0, 5);
// 	if (!result)
// 		printf("| [SUCCÈS] | NULL input\n");
// 	else
// 		printf("| %-20s | [ÉCHOUÉ] |\n",  result);
// 	free(result);
// }
