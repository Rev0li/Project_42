/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:20:12 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/21 10:22:20 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

t_stack	*ft_lstmin(t_stack *stack)
{
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->f_index < min_node->f_index)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*ft_lstmax(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->f_index > max_node->f_index)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}
