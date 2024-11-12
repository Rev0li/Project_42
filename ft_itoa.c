/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:31:04 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/12 13:13:48 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	alloc(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*special_cases(int n)
{
	char	*result;

	if (n == -2147483648)
	{
		result = (char *)malloc(12 * sizeof(char));
		if (!result)
			return (NULL);
		ft_strlcpy(result, "-2147483648", 12);
		return (result);
	}
	if (n == 0)
	{
		result = (char *)malloc(2 * sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		is_negative;
	int		len;

	result = special_cases(n);
	if (result)
		return (result);
	len = alloc(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	is_negative = (n < 0);
	if (is_negative)
		n = -n;
	while (len--)
	{
		result[len] = n % 10 + '0';
		n = n / 10;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}
