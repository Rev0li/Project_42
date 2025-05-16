/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:36:38 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 19:36:38 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** lstlast *****/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		write(2, "Err : pt NULL in ft_lstlast\n", 28);
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
