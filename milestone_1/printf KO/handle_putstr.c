/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:15:33 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/20 09:54:51 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	handle_character(char c)
{
	write(1, &c, 1);
	return (1);
}

int	handle_string(char *str, int written)
{
	if (str == NULL)
	{
		written = write(1, "(null)", 6);
		return (written);
	}
	while (*str)
	{
		write(1, str, 1);
		written++;
		str++;
	}
	return (written);
}

int	handle_percent(void)
{
	write(1, "%", 1);
	return (1);
}
