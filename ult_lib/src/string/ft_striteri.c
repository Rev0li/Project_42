/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:04:51 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 09:04:51 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** striteri *****/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
	{
		write(2, "Error : pointer s NULL in ft_striteri\n", 38);
		return ;
	}
	if (!f)
	{
		write(2, "Error : pointer f NULL in ft_striteri\n", 38);
		return ;
	}
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
