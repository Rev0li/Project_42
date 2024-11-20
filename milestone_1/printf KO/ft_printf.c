/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:12:36 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/20 09:51:57 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	splitter(va_list args, const char *format, int written)
{
	if (*format == '%')
		written += handle_percent();
	if (*format == 'c')
		written += handle_character(va_arg(args, int));
	if (*format == 's')
		written += handle_string(va_arg(args, char *), written);
	if (*format == 'p')
		written += handle_pointer(va_arg(args, uintptr_t), written);
	if (*format == 'd' || *format == 'i')
		written += handle_decimal(va_arg(args, int), written);
	if (*format == 'u')
		written += handle_unsigned(va_arg(args, unsigned int), written);
	if (*format == 'x')
		written += handle_hexa_low(va_arg(args, unsigned int), written);
	if (*format == 'X')
		written += handle_hexa_up(va_arg(args, unsigned int), written);
	return (written);
}

int	ft_printf(const char *format, ...)
{
	int		written;
	va_list	args;

	va_start(args, format);
	written = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			written += splitter(args, format, written);
			format++;
		}
		write(1, format, 1);
		written++;
		format++;
	}
	va_end(args);
	return (written);
}
