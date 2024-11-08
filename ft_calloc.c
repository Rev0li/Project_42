/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:28:46 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 18:13:18 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr = malloc(count * size);
	if (!ptr)
		return NULL;
	memset(ptr, 0, count * size); // Initialisation à zéro
	return ptr;
}

