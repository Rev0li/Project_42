/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 07:45:21 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/26 09:25:01 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_pointer(uintptr_t ptr, int len)
{
	if (ptr < 16)
	{
		if (ptr <= 9)
		{
			if (ft_putchar(ptr + '0') < 0)
				return (-1);
		}
		else
		{
			if (ft_putchar(ptr -10 + 'a') < 0)
				return (-1);
		}
		return (1);
	}
	else
	{
		len = print_pointer(ptr / 16, len);
		len += print_pointer(ptr % 16, len);
	}
	return (len);
}

int	ft_pointer(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	return (len + print_pointer(ptr, len));
}
