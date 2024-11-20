/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:53:53 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/20 09:47:07 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n, int written)
{
	char	c;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (written + 11);
		}
		write (1, "-", 1);
		written++;
		n = -n;
	}
	if (n >= 10)
	{
		written = ft_putnbr(n / 10, written);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (written + 1);
}
