/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:11:49 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:05:05 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ult_lib.h"

/***** lstiter *****/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
	{
		ft_printf("Erreur : pointeur NULL passé pour lst dans ft_lstiter\n");
		return ;
	}
	if (!f)
	{
		ft_printf("Erreur : pointeur NULL passé pour f dans ft_lstiter\n");
		return ;
	}
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/***** lstlast *****/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		ft_printf("Erreur : pointeur NULL passé pour lst dans ft_lstlast\n");
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

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
		ft_printf("Erreur : échec de l'allocation mémoire dans ft_lstmap\n");
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
		ft_printf("Erreur : pointeur NULL passé dans ft_lstmap\n");
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

/***** lstsize *****/
int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
	{
		ft_printf("Erreur : pointeur NULL passé pour lst dans ft_lstsize\n");
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
