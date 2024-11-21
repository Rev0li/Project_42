/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:53:53 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/20 08:44:29 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_base(unsigned long int n, char *base, int l_base, int written)
{
	char	c;

	if (n >= (unsigned long int)l_base)
	{
		written = ft_putnbr_base(n / l_base, base, l_base, written);
	}
	c = base[n % l_base];
	write(1, &c, 1);
	return (written + 1);
}
