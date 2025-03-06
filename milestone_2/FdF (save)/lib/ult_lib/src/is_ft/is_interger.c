/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_interger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:23:48 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 18:24:43 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>

int	is_to_long(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 12)
		return (1);
	else
		return (0);
}

int	is_integer(char *str)
{
	long	num;
	int		i;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	if (is_to_long(str))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (num * sign < INT_MIN || num * sign > INT_MAX)
		return (0);
	return (1);
}
