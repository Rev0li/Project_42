/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:53:29 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 12:05:58 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
/////////// TEST
// #include <stdio.h>
// #include <string.h>
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new_node;
//
// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->content = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }
//
//
// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// }
//
// void	del(void *content)
// {
// 	free(content);
// }
//
// void	list(t_list *lst)
// {
// 	while (lst)
// 	{
// 	printf("%s \n", (char*)lst->content);
// 	lst = lst->next;
// 	}
// 	printf("NULL\n");
// }
//
// int	main()
// {
// 	t_list	*lst = ft_lstnew(strdup("first"));
// 	lst->next = ft_lstnew(strdup("second"));
// 	lst->next->next = ft_lstnew(strdup("third"));
//
// 	printf("\nBefore :\n");
// 	list(lst);
// 	ft_lstclear(&lst, del);
// 	printf("\nAfter :\n");
// 	list(lst);
// }
