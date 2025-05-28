/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:42:21 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/13 19:23:40 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/memory.h"
#include "../../includes/philo.h"
#include <stdlib.h>
#include <stdio.h>

static t_mem_node	**get_mem_list(void)
{
	static t_mem_node	*head = NULL;

	return (&head);
}

void	mem_register(void *ptr, t_data *data)
{
	t_mem_node	*node;
	t_mem_node	**head;

	head = get_mem_list();
	node = malloc(sizeof * node);
	if (node == NULL)
	{
		printf("error: malloc\n");
		mem_free_all();
		return  (1);
	}
	node->ptr = ptr;
	node->next = *head;
	*head = node;
	return (0);
}

void	mem_free_all(void)
{
	t_mem_node	*cur;
	t_mem_node	*tmp;
	t_mem_node	**head;

	head = get_mem_list();
	cur = *head;
	while (cur)
	{
		free(cur->ptr);
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	*head = NULL;
}

void	*ft_xmalloc(size_t size, t_data *data)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
	{
		printf("error: malloc\n");
		mem_free_all();
		return (NULL);
	}
	if (mem_register(p, data))
		return(NULL);
	return (p);
}
