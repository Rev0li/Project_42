/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:16:40 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 14:15:42 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/checker_bonus.h"

static void	reverse_rotate_b(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra_b(t_stack **a)
{
	reverse_rotate_b(a);
}

void	rrb_b(t_stack **b)
{
	reverse_rotate_b(b);
}

void	rrr_b(t_stack **a, t_stack **b)
{
	reverse_rotate_b(a);
	reverse_rotate_b(b);
}
