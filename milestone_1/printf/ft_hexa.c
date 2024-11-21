/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:17:57 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/21 11:47:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_hexa(unsigned int n, int i, int len)
{
	if (n < 16)
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a' - i);
		return (1);
	}
	else
	{
		len = print_hexa(n / 16, i, len);
		len += print_hexa(n % 16, i, len);
	}
	return (len);
}

int	ft_hexa(unsigned int n, const char *s)
{
	int	len;

	len = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (*s == 'x')
		return (print_hexa(n, 0, len));
	if (*s == 'X')
		return (print_hexa(n, 32, len));
	return (0);
}
