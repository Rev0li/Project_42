/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:31:04 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/26 08:34:12 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	ln;
	char	digits[12];
	int		i;
	int		len;

	len = 0;
	ln = n;
	if (ln < 0)
	{
		len += ft_putchar('-');
		ln = -ln;
	}
	if (ln == 0)
		return (ft_putchar('0'));
	i = 0;
	while (ln > 0)
	{
		digits[i++] = (ln % 10) + '0';
		ln = ln / 10;
	}
	while (--i >= 0)
		len += ft_putchar(digits[i]);
	return (len);
}
