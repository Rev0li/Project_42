/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:22:58 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:04:09 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ult_lib.h"

/***** putunbr *****/
int	ft_putunbr(unsigned int n)
{
	char	digits[12];
	int		i;
	int		len;

	len = 0;
	if (n == 0)
		return (printf_putchar('0'));
	i = 0;
	while (n > 0)
	{
		digits[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (--i >= 0)
		len += printf_putchar(digits[i]);
	return (len);
}

/***** pointer *****/
static int	print_pointer(uintptr_t ptr, int len)
{
	if (ptr < 16)
	{
		if (ptr <= 9)
			printf_putchar(ptr + '0');
		else
			printf_putchar(ptr -10 + 'a');
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
		return (printf_putstr("(nil)"));
	len = printf_putstr("0x");
	return (len + print_pointer(ptr, len));
}

/***** hexa *****/
int	print_hexa(unsigned int n, int i, int len)
{
	if (n < 16)
	{
		if (n <= 9)
			printf_putchar(n + '0');
		else
			printf_putchar(n - 10 + 'a' - i);
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
		return (printf_putchar('0'));
	if (*s == 'x')
		return (print_hexa(n, 0, len));
	if (*s == 'X')
		return (print_hexa(n, 32, len));
	return (0);
}
