/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:41:39 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/13 11:29:14 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_strlcpy\n");
		return (0);
	}
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

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
			++count;
		}
		else if (*s == c)
			in_word = 0;
		++s;
	}
	return (count);
}

static char	*malloc_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		++len;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
	{
		ft_printf("Erreur : échec de l'allocation mémoire dans malloc_word\n");
		return (NULL);
	}
	ft_strlcpy(word, s, len+1)
	return (word);
}

static char	**free_all(char **result, int i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return (NULL);
}


char	**push_split(char const *s, char c) //  ( "21 1 5 3" , ' ')
{
	char 	**result;
	size_t		i;

	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = malloc_word(s, c);
			if (!result[i++])
				return (free_all(result, i - 1));
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	result[i] = NULL;
	return (result);

}
