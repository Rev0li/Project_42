/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:28:14 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:05:34 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ult_lib.h"

/***** strdup *****/
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	if (!s)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_strdup\n");
		return (NULL);
	}
	len = ft_strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
	{
		ft_printf("Erreur : échec de l'allocation mémoire dans ft_strdup\n");
		return (NULL);
	}
	ft_memcpy(copy, s, len);
	copy[len] = '\0';
	return (copy);
}

/***** substr *****/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;

	if (!s)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_substr\n");
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
	{
		ft_printf("Erreur : échec de l'allocation mémoire dans ft_substr\n");
		return (NULL);
	}
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

/***** striteri *****/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
	{
		ft_printf("Erreur : pointeur NULL passé pour s dans ft_striteri\n");
		return ;
	}
	if (!f)
	{
		ft_printf("Erreur : pointeur NULL passé pour f dans ft_striteri\n");
		return ;
	}
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/***** strtrim *****/
static void	get_trim_bounds(char const *s1, char const *set,
		size_t *start, size_t *end)
{
	*start = 0;
	*end = ft_strlen(s1);
	while (s1[*start] && ft_strchr(set, s1[*start]))
		(*start)++;
	while (*end > *start && ft_strchr(set, s1[*end - 1]))
		(*end)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_strtrim\n");
		return (NULL);
	}
	get_trim_bounds(s1, set, &start, &end);
	result = malloc((end - start + 1) * sizeof(char));
	if (!result)
	{
		ft_printf("Erreur : échec de l'allocation mémoire dans ft_strtrim\n");
		return (NULL);
	}
	ft_strlcpy(result, &s1[start], end - start + 1);
	return (result);
}
