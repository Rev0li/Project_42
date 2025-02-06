/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:38:11 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 14:14:48 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/checker_bonus.h"

static void	swap_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa_b(t_stack **a)
{
	swap_b(a);
}

void	sb_b(t_stack **b)
{
	swap_b(b);
}

void	ss_b(t_stack **a, t_stack **b)
{
	swap_b(a);
	swap_b(b);
}
