/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_mv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:11:07 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 12:15:44 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static int	adjust_if_end(t_stack *current_b, t_stack *b, t_stack *current_a)
{
	if (!current_b->next && current_a->f_index < current_b->f_index
		&& current_a->f_index > b->f_index)
		return (1);
	return (0);
}

static int	move_to_max(t_stack *current_b, t_stack *b, t_stack *current_a)
{
	int	mv;

	mv = 0;
	while (current_b->f_index != ft_lstmax(b)->f_index)
	{
		current_b = current_b->next;
		mv++;
	}
	return (mv + adjust_if_end(current_b, b, current_a));
}

static int	move_between_elements(t_stack *cur_b, t_stack *cur_a, t_stack *b)
{
	int	mv;

	mv = 0;
	while (cur_b->next)
	{
		if (cur_a->f_index < cur_b->f_index
			&& cur_a->f_index > cur_b->next->f_index)
		{
			mv++;
			return (mv);
		}
		cur_b = cur_b->next;
		mv++;
	}
	return (mv + adjust_if_end(cur_b, b, cur_a));
}

static	void	fill_mv_b(int mv, int size_b, t_stack *current_a)
{
	if (mv <= size_b / 2)
	{
		current_a->mv_b = mv;
		current_a->b_up_or_down = 1;
	}
	else
	{
		current_a->mv_b = size_b - mv;
		current_a->b_up_or_down = -1;
	}
}

void	assign_mv_b(t_stack **a, t_stack **b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		mv;
	int		size_b;

	size_b = ft_lstsize(*b);
	current_a = *a;
	while (current_a)
	{
		current_b = *b;
		mv = 0;
		if (current_a->f_index > ft_lstmax(*b)->f_index
			|| current_a->f_index < ft_lstmin(*b)->f_index)
			mv = move_to_max(current_b, *b, current_a);
		else
			mv = move_between_elements(current_b, current_a, *b);
		fill_mv_b(mv, size_b, current_a);
		current_a = current_a->next;
	}
}
