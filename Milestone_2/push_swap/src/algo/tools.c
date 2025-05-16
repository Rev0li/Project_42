/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:58:29 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 12:16:22 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	sort_b(t_stack **b)
{
	t_stack	*current_b;
	int		mv;
	int		size_b;

	mv = 0;
	current_b = *b;
	size_b = ft_lstsize(*b);
	while (ft_lstmax(*b)->f_index != current_b->f_index)
	{
		current_b = current_b->next;
		mv++;
	}
	if (mv <= size_b / 2)
	{
		while (mv-- > 0)
			rb(b);
	}
	else
	{
		mv = size_b - mv;
		while (mv-- > 0)
			rrb(b);
	}
}

void	sort_a(t_stack **a)
{
	t_stack	*current_a;
	int		mv;
	int		size_a;

	mv = 0;
	current_a = *a;
	size_a = ft_lstsize(*a);
	while (ft_lstmin(*a)->f_index != current_a->f_index)
	{
		current_a = current_a->next;
		mv++;
	}
	if (mv <= size_a / 2)
	{
		while (mv-- > 0)
			ra(a);
	}
	else
	{
		mv = size_a - mv;
		while (mv-- > 0)
			rra(a);
	}
}

void	assign_mv_a(t_stack **a)
{
	t_stack	*current;
	int		mv;
	int		size;

	size = ft_lstsize(*a);
	mv = 0;
	current = *a;
	while (current)
	{
		if (mv <= size / 2)
		{
			current->mv_a = mv;
			current->a_up_or_down = 1;
		}
		else
		{
			current->mv_a = size - mv;
			current->a_up_or_down = -1;
		}
		current = current->next;
		mv++;
	}
}
