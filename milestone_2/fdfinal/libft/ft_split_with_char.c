/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:52:55 by jkasongo          #+#    #+#             */
/*   Updated: 2022/10/05 21:23:29 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

static inline size_t	split_and_count(char *line, const char *str, size_t len)
{
	size_t	count;
	size_t	i;
	char	*s;

	count = 0;
	s = line;
	while (*s != 0)
	{
		if (is_in_set(*s, str) == 0)
			*s = 0;
		s++;
	}
	i = 0;
	while (i < len)
	{
		if (line[i] == 0)
			count++;
		while (line[i] == 0)
			i++;
		i++;
	}
	return (count);
}

static inline void	ft_splitter(char **words, char *line, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < len)
	{
		while (line[i] == 0)
			i++;
		words[j] = ft_strdup(&line[i]);
		i += ft_strlen(words[j++]);
	}
}

char	**ft_split_v(char *line, char *str)
{
	size_t	line_len;
	size_t	count;
	char	**split;
	char	*l;

	line_len = ft_strlen(line);
	l = ft_strdup(line);
	if (line_len > 0)
	{
		count = split_and_count(l, str, line_len);
		split = (char **)ft_calloc(count + 2, sizeof(char *));
		ft_splitter(split, l, count + 1);
		free(l);
		return (split);
	}
	return (0);
}
