/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:00:08 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 09:00:08 by okientzl         ###   ########.fr       */
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
