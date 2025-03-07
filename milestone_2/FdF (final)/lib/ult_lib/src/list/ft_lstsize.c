/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:34:12 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 19:34:53 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** lstsize *****/
int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
	{
		write(2, "Err : ptr NULL in ft_lstsize\n", 29);
		return (0);
	}
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
