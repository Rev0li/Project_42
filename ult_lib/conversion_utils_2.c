/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:43:48 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/10 18:48:54 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ult_lib.h"
#include <limits.h>

/***** atoi *****/
static size_t	skip_whitespace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	return (i);
}

static int	get_sign(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	handle_overflow(long long result, int sign)
{
	if (result * sign > INT_MAX)
	{
		ft_printf("Erreur : dépassement de INT_MAX\n");
		return (INT_MAX);
	}
	if (result * sign < INT_MIN)
	{
		ft_printf("Erreur : dépassement de INT_MIN\n");
		return (INT_MIN);
	}
	return ((int)(result * sign));
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	result;

	i = skip_whitespace(str);
	sign = get_sign(str, &i);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (handle_overflow(result, sign));
}
