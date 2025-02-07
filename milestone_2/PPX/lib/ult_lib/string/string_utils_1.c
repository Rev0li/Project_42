/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:18:30 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:05:28 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ult_lib.h"

/***** ft_strlen *****/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_strlen\n");
		return (0);
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/***** ft_strlcpy *****/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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

/***** ft_strlcat *****/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_strlcat\n");
		return (0);
	}
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/***** ft_strchr *****/
char	*ft_strchr(const char *s, int c)
{
	if (!s)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_strchr\n");
		return (NULL);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/***** ft_strrchr *****/
char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	if (!s)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_strrchr\n");
		return (NULL);
	}
	while (*s)
	{
		if (*s == (char)c)
			last_occurrence = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}
