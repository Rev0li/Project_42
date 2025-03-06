/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:27:39 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 19:27:39 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** lstadd_front *****/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
	{
		write(2, "Err: ptr NULL for lst in ft_lstadd_front\n", 41);
		return ;
	}
	if (!new)
	{
		write(2, "Err: ptr NULL for new in ft_lstadd_front\n", 41);
		return ;
	}
	new->next = *lst;
	*lst = new;
}
