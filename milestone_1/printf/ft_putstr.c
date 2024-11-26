/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:38:29 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/26 09:17:36 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char const *s)
{
	int	len;

	if (s == NULL)
		return (ft_putstr("(null)"));
	len = ft_strlen(s);
	if (write(1, s, len) < 0)
		return (-1);
	return (len);
}
