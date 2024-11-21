/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:57:23 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/21 14:05:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	char	digits[12];
	int		i;
	int		len;

	len = 0;
	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	while (n > 0)
	{
		digits[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (--i >= 0)
		len += ft_putchar(digits[i]);
	return (len);
}
