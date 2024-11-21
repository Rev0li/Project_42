/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:57:29 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 15:10:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	result = malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[start], end - start + 1);
	return (result);
}
// #include <stdio.h>
// #include <string.h>
// int	ft_strlen(const char *string);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// char	*ft_strchr(const char *s, int c);
//
// int main()
// {
//     char *result;
//     char expected[50];
//
//     result = ft_strtrim("   hello   ", " ");
//     snprintf(expected, sizeof(expected), "%s", "hello");
//     if (result && strcmp(result, expected) == 0)
//         printf("[SUCCÈS] | trimmed spaces\n");
//     else
//         printf("| %-20s | [ÉCHOUÉ]  | trimmed spaces\n", result);
//     free(result);
//
//     result = ft_strtrim("**42isAwesome**", "*");
//     snprintf(expected, sizeof(expected), "%s", "42isAwesome");
//     if (result && strcmp(result, expected) == 0)
//         printf("[SUCCÈS]  | trimmed *\n");
//     else
//         printf("| %-20s | [ÉCHOUÉ]  | trimmed *\n", result);
//     free(result);
//
//     result = ft_strtrim("", " ");
//     snprintf(expected, sizeof(expected), "%s", "");
//     if (result && strcmp(result, expected) == 0)
//         printf("[SUCCÈS]  | empty string\n");
//     else
//         printf("| %-20s | [ÉCHOUÉ]  | empty string\n", result);
//     free(result);
//
//     result = ft_strtrim("hello", "");
//     snprintf(expected, sizeof(expected), "%s", "hello");
//     if (result && strcmp(result, expected) == 0)
//         printf("[SUCCÈS]  | empty set\n");
//     else
//         printf("| %-20s | [ÉCHOUÉ]  | empty set\n", result);
//     free(result);
//
//     result = ft_strtrim("xxxx", "x");
//     snprintf(expected, sizeof(expected), "%s", "");
//     if (result && strcmp(result, expected) == 0)
//         printf("[SUCCÈS]  | all trimmed\n");
//     else
//         printf("| %-20s | [ÉCHOUÉ]  | all trimmed\n", result);
//     free(result);
//
//     result = ft_strtrim("$$$hello$$$", "$");
//     snprintf(expected, sizeof(expected), "%s", "hello");
//     if (result && strcmp(result, expected) == 0)
//         printf("[SUCCÈS] | trimmed $\n");
//     else
//         printf("| %-20s | [ÉCHOUÉ]  | trimmed $\n", result);
//     free(result);
// }
// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	j;
//
// 	i = 0;
// 	j = 0;
// 	while (src[i] != '\0')
// 		i++;
// 	if (size == 0)
// 		return (i);
// 	while (j < size - 1 && src[j] != '\0')
// 	{
// 		dst[j] = src[j];
// 		j++;
// 	}
// 	if (size > 0)
// 		dst[j] = '\0';
// 	return (i);
// }
// int	ft_strlen(const char *string)
// {
// 	int	i;
//
// 	i = 0;
// 	while (string[i] != '\0')
// 		i++;
// 	return (i);
// }
// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)s);
// 	return (NULL);
// }
