/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:06:57 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/20 08:44:42 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	handle_decimal(int args, int written)
{
	written = ft_putnbr(args, written);
	return (written);
}

int	handle_pointer(unsigned long int args, int written)
{
	if (args == 0)
	{
		written = write(1, "(nil)", 5);
		return (written);
	}
	write(1, "0x", 2);
	written = ft_putnbr_base(args, "0123456789abcdef", 16, written);
	return (written + 2);
}

int	handle_unsigned(unsigned int args, int written)
{
	written = ft_putnbr_base(args, "0123456789", 10, written);
	return (written);
}

int	handle_hexa_low(unsigned int args, int written)
{
	written = ft_putnbr_base(args, "0123456789abcdef", 16, written);
	return (written);
}

int	handle_hexa_up(unsigned int args, int written)
{
	written = ft_putnbr_base(args, "0123456789ABCDEF", 16, written);
	return (written);
}
