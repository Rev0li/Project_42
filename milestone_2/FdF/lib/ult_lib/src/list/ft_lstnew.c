/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:33:20 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 19:33:20 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** lstnew *****/
t_list	*ft_lstnnnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		write(2, "Err : Fail malloc in ft_lstnew\n", 31);
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
