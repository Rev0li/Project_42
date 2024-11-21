/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:08:35 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 14:13:39 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
// int	ft_strlen(const char *string)
// {
// 	int	i;
//
// 	i = 0;
// 	while (string[i] != '\0')
// 		i++;
// 	return (i);
// }
// char	*ft_strdup(const char *s)
// {
// 	size_t	len;
// 	size_t	i;
// 	char	*copy;
//
// 	i = 0;
// 	len = ft_strlen(s);
// 	copy = (char *)malloc((len + 1) * sizeof(char));
// 	if (!copy)
// 		return (NULL);
// 	while (i <= len)
// 	{
// 		copy[i] = s[i];
// 		i++;
// 	}
// 	return (copy);
// }
// #include <stdio.h>
// #include <string.h> 
// int	main()
// {
//     char *result;
//     char expected[50]
// 		;
//     result = ft_strjoin("hello", "world");
//     snprintf(expected, sizeof(expected), "%s", "helloworld");
//     if (result && strcmp(result, expected) == 0)
//         printf("| %-20s | [SUCCÈS]|\n", "\"hello\", \"world\"");
//     else
//         printf("|%-20s|[ÉCHOUÉ] Résultat:%s|\n","hello,world",result);
//     free(result);
//
//     result = ft_strjoin("", "world");
//     snprintf(expected, sizeof(expected), "%s", "world");
//     if (result && strcmp(result, expected) == 0)
//         printf("| %-20s | [SUCCÈS]|\n", "\"\", \"world\"");
//     else
//         printf("| %-20s | [ÉCHOUÉ] Résultat: %s|\n","\"\",world",result);
//     free(result);
//
//     result = ft_strjoin("hello", "");
//     snprintf(expected, sizeof(expected), "%s", "hello");
//     if (result && strcmp(result, expected) == 0)
//         printf("| %-20s | [SUCCÈS]|\n", "\"hello\", \"\"");
//     else
//         printf("| %-20s |[ÉCHOUÉ]Résultat:%s|\n","hello,\"\"",result);
//     free(result);
//
//     result = ft_strjoin("", "");
//     snprintf(expected, sizeof(expected), "%s", "");
//     if (result && strcmp(result, expected) == 0)
//         printf("| %-20s | [SUCCÈS]|\n", "empty");
//     else
//         printf("| %-20s | [ÉCHOUÉ] Résultat: %s|\n","empty", result);
//     free(result);
//
//     result = ft_strjoin(NULL, "world");
//     snprintf(expected, sizeof(expected), "%s", "world");
// 	if (result && strcmp(result, expected) == 0)
//         printf("| %-20s | [SUCCÈS]|\n", "NULL + world");
//     else
//         printf("| %-20s |[ÉCHOUÉ]Résultat: %s|\n","NULL + world",result);
//     free(result);
//
//     result = ft_strjoin("hello", NULL);
//     snprintf(expected, sizeof(expected), "%s", "hello");
// 	if (result && strcmp(result, expected) == 0)
//         printf("| %-20s | [SUCCÈS]|\n", "hello + NULL");
//     else
//         printf("| %-20s |[ÉCHOUÉ]Résultat: %s|\n","hello + NULL",result);
//     free(result);
//
//     result = ft_strjoin(NULL, NULL);
//     if (!result)
//         printf("| %-20s | [SUCCÈS]|\n", "NULL + NULL");
//     else
//         printf("| %-20s |[ÉCHOUÉ] Résultat:%s|\n","NULL+NULL",result);
//     free(result);
// }
