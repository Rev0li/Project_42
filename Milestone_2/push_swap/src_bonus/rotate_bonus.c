/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:16:44 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 14:15:23 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/checker_bonus.h"

static void	rotate_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra_b(t_stack **a)
{
	rotate_b(a);
}

void	rb_b(t_stack **b)
{
	rotate_b(b);
}

void	rr_b(t_stack **a, t_stack **b)
{
	rotate_b(a);
	rotate_b(b);
}
