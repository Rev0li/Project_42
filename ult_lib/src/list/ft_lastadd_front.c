/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:58:22 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:58:22 by okientzl         ###   ########.fr       */
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
