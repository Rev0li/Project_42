/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:56:31 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 12:38:01 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*malloc_word(char const *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = s[len];
	return (word);
}

static char	**free_all(char **result, int i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			result[i] = malloc_word(s, c);
			if (!result[i++])
				return (free_all(result, i - 1));
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
// #include <stdio.h>
// #include <string.h>
// void check_split_result(char **result, 
// char **expected, const char *description)
// {
//     int i = 0;
//     int success = 1;
//
//     while (expected[i])
//     {
//         if (!result[i] || strcmp(result[i], expected[i]) != 0)
//         {
//             success = 0;
//             break;
//         }
//         i++;
//     }
//
//     if (success && !result[i]) 
// 		printf("| %-20s | [SUCCÈS] |\n", description);
//     else
//     {
//         printf("| %-20s | [ÉCHOUÉ] Résultat: ", description);
//         i = 0;
//         while (result && result[i])
//         {
//             printf("\"%s\" ", result[i]);
//             free(result[i]);
//             i++;
//         }
//         printf("|\n");
//     }
//     free(result);
// }
// int	main()
// {
//     char **result;
//     char *expected1[] = {"hello", "world", "42", NULL};
//     char *expected2[] = {"42", "school", NULL};
//     char *expected3[] = {"hello", NULL};
//     char *expected4[] = {NULL};
//     char *expected5[] = {"hello", NULL};
//     char *expected6[] = {NULL};
//
//     result = ft_split("hello world 42", ' ');
//     check_split_result(result, expected1, "split spaces");
//
//     result = ft_split("42---school", '-');
//     check_split_result(result, expected2, "split -");
//
//     result = ft_split("--hello--", '-');
//     check_split_result(result, expected3, "split edge -");
//
//     result = ft_split("", ' ');
//     check_split_result(result, expected4, "split empty string");
//
//     result = ft_split("hello", '-');
//     check_split_result(result, expected5, "no delimiters");
//
//     result = ft_split("---", '-');
//     check_split_result(result, expected6, "delimiter only -");
//
// }
