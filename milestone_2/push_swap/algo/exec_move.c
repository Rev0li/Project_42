/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:06:55 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/21 10:07:04 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	if_syncro(t_stack *best, t_stack **a, t_stack **b)
{
	while (best->mv_a > 0 && best->mv_b > 0)
	{
		if (best->a_up_or_down == 1 && best->b_up_or_down == 1)
		{
			rr(a, b);
		}
		else if (best->a_up_or_down == -1 && best->b_up_or_down == -1)
		{
			rrr(a, b);
		}
		best->mv_a--;
		best->mv_b--;
	}
}

static void	if_asyncro(t_stack *best, t_stack **a, t_stack **b)
{
	while (best->mv_a > 0)
	{
		if (best->a_up_or_down == 1)
			ra(a);
		else
			rra(a);
		best->mv_a--;
	}
	while (best->mv_b > 0)
	{
		if (best->b_up_or_down == 1)
			rb(b);
		else
			rrb(b);
		best->mv_b--;
	}
}

void	exec_mv(t_stack **a, t_stack **b, int index)
{
	t_stack	*best;

	best = *a;
	while (best->f_index != index)
		best = best->next;
	if (best->a_up_or_down == best->b_up_or_down)
		if_syncro(best, a, b);
	if_asyncro(best, a, b);
}
