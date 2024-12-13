/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:51:31 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/10 19:07:44 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ult_lib.h"

/***** lstnew *****/
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		ft_printf("Erreur : échec de l'allocation mémoire dans ft_lstnew\n");
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/***** lstadd_back *****/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst)
	{
		ft_printf("Err: ptr NULL pour lst dans ft_lstadd_back\n");
		return ;
	}
	if (!new)
	{
		ft_printf("Err: ptr NULL pour new dans ft_lstadd_back\n");
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

/***** lstadd_front *****/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
	{
		ft_printf("Err: ptr NULL pour lst dans ft_lstadd_front\n");
		return ;
	}
	if (!new)
	{
		ft_printf("Err: ptr NULL pour new dans ft_lstadd_front\n");
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/***** lstdelone *****/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
	{
		ft_printf("Erreur : pointeur NULL passé pour lst dans ft_lstdelone\n");
		return ;
	}
	if (!del)
	{
		ft_printf("Erreur : pointeur NULL passé pour del dans ft_lstdelone\n");
		return ;
	}
	del(lst->content);
	free(lst);
}

/***** lstclear *****/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst)
	{
		ft_printf("Erreur : pointeur NULL passé pour lst dans ft_lstclear\n");
		return ;
	}
	if (!del)
	{
		ft_printf("Erreur : pointeur NULL passé pour del dans ft_lstclear\n");
		return ;
	}
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
