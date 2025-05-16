/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:59:18 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:59:18 by okientzl         ###   ########.fr       */
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
