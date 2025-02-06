/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_index_to_mv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:54:55 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 12:15:57 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static int	calculate_combined_moves(t_stack *node)
{
	if (node->a_up_or_down == node->b_up_or_down)
	{
		if (node->mv_a < node->mv_b)
			return (node->mv_a);
		else
			return (node->mv_b);
	}
	return (0);
}

static int	calculate_total_cost(t_stack *node)
{
	int	combined_moves;

	combined_moves = calculate_combined_moves(node);
	return (node->mv_a + node->mv_b - combined_moves);
}

int	best_index_to_mv(t_stack **a)
{
	t_stack	*current;
	t_stack	*best;
	int		current_cost;
	int		best_cost;

	current = *a;
	best = *a;
	best_cost = calculate_total_cost(best);
	while (current)
	{
		current_cost = calculate_total_cost(current);
		if (current_cost < best_cost)
		{
			best = current;
			best_cost = current_cost;
		}
		current = current->next;
	}
	return (best->f_index);
}
