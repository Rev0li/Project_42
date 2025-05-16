/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:59:29 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:59:29 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** lstiter *****/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
	{
		write(2, "Err : ptr NULL for lst in ft_lstiter\n", 37);
		return ;
	}
	if (!f)
	{
		write(2, "Err : ptr NULL for f in ft_lstiter\n", 35);
		return ;
	}
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
