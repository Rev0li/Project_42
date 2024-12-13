/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:56:03 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/13 08:01:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void display_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

char	**push_split(char const *s, char c) //  ( "21 1 5 3" , ' ')
{
	char 	**result;
	int		i;

	if (!s)
		return (NULL);
}
