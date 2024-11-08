/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:14:33 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 18:12:25 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	// Conversion du pointeur 's' en 'unsigned char *'
	unsigned char *ptr = (unsigned char *)s; 	
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
