/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:07:13 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/26 08:37:30 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static t_stack	*ft_lstnew(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	current = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	init_stack(size_t ac, char **av, t_stack **a)
{
	t_stack	*new_node;
	size_t	i;

	i = 1;
	while (i < ac)
	{
		new_node = ft_lstnew(ft_atoi(av[i]));
		if (!new_node)
		{
			free_stack(a);
			return (1);
		}
		ft_lstadd_back(a, new_node);
		i++;
	}
	return (0);
}
