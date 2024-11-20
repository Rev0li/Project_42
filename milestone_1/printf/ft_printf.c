/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:36:38 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/20 12:49:55 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	splitter(va_list args, const char *s)
{
	if (*s == '%')
		return (ft_putchar('%'));
	if (*s == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(args, char *)));
	// if (*s == 'p')
	// 	written += handle_pointer(va_arg(args, uintptr_t), written);
	// if (*s == 'd' || *s == 'i')
	// 	written += handle_decimal(va_arg(args, int), written);
	// if (*s == 'u')
	// 	written += handle_unsigned(va_arg(args, unsigned int), written);
	// if (*s == 'x')
	// 	written += handle_hexa_low(va_arg(args, unsigned int), written);
	// if (*s == 'X')
	// 	written += handle_hexa_up(va_arg(args, unsigned int), written);
	return (-1);
}


int	convert(const char *s, va_list args, int len)
{
	int	tmp;

	while (*s)
	{
		if(*s == '%')
		{
			tmp = 0;
			tmp = splitter(args, (++s));
			if(tmp == -1)
				return (-1);
			len += tmp;
		}
		else
			len += ft_putchar(*s);
		s++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	args;

	len = 0;
	if (s == NULL)
		return (-1);
	va_start(args, s);
	len = convert(s, args, len); 
	va_end(args);
	return (len);
}
