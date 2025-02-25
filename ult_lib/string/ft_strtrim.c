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
