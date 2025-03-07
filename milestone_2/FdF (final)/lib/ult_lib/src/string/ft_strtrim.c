/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:43:23 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 17:43:23 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"
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
		write(2, "Error : pointer NULL in ft_strtrim\n", 35);
		return (NULL);
	}
	get_trim_bounds(s1, set, &start, &end);
	result = malloc((end - start + 1) * sizeof(char));
	if (!result)
	{
		write(2, "Error : Fail malloc in ft_strtrim\n", 34);
		return (NULL);
	}
	ft_strlcpy(result, &s1[start], end - start + 1);
	return (result);
}
