/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:31:58 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 19:31:58 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** lstdelone *****/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
	{
		write(2, "Err : ptr NULL for lst in ft_lstdelone\n", 39);
		return ;
	}
	if (!del)
	{
		write(2, "Err : ptr NULL for del in ft_lstdelone\n", 39);
		return ;
	}
	del(lst->content);
	free(lst);
}
