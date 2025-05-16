/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:59:48 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:59:48 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** lstmap *****/
static int	create_and_add_node(t_list **new_list,
		void *new_content, void (*del)(void *))
{
	t_list	*new_elem;

	new_elem = ft_lstnew(new_content);
	if (!new_elem)
	{
		ft_lstclear(new_list, del);
		del(new_content);
		write(2, "Err : Fail malloc in ft_lstmap\n", 31);
		return (0);
	}
	ft_lstadd_back(new_list, new_elem);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*new_content;

	if (!lst || !f || !del)
	{
		write(2, "Err : ptr NULL in ft_lstmap\n", 28);
		return (NULL);
	}
	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		if (!create_and_add_node(&new_list, new_content, del))
			return (NULL);
		lst = lst->next;
	}
	return (new_list);
}
