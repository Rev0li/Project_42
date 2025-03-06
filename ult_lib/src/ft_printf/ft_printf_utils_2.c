/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:13:03 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:04:06 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** printf_putchar *****/
int	printf_putchar(char c)
{
	if (write(1, &c, 1) == -1)
	{
		write(2, "Err: Fail write in ft_putchar_fd\n", 33);
		return (-1);
	}
	return (1);
}

/***** printf_putnbr *****/
int	printf_putnbr(int n)
{
	long	ln;
	char	digits[12];
	int		i;
	int		len;

	len = 0;
	ln = n;
	if (ln < 0)
	{
		len += printf_putchar('-');
		ln = -ln;
	}
	if (ln == 0)
		return (printf_putchar('0'));
	i = 0;
	while (ln > 0)
	{
		digits[i++] = (ln % 10) + '0';
		ln = ln / 10;
	}
	while (--i >= 0)
		len += printf_putchar(digits[i]);
	return (len);
}

/***** printf_putstr *****/
int	printf_putstr(char *s)
{
	int	len;

	if (s == NULL)
		return (printf_putstr("(null)"));
	len = ft_strlen(s);
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}
