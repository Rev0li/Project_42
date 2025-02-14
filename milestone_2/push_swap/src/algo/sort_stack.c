/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:31:17 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/14 04:27:15 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static void	sort_to_b(t_stack **a, t_stack **b)
{
	int	index;
	/*int	threshold;*/
	/**/
	/*threshold = ft_lstsize(*a) / 10;*/
	while (*a)
	{
		if (ft_lstsize(*a) > 32)
		{
			assign_mv_a(a);
			assign_mv_b(a, b);
			index = best_index_to_mv(a);
			exec_mv(a, b, index);
			pb(a, b);
		}
		else
			break ;
	}
	small_sort(a, b);
}

static void	final_push_a(t_stack **a, t_stack **b)
{
	if (ft_lstlast(*a)->f_index > (*b)->f_index)
		rra(a);
	while (*b)
	{
		if (ft_lstlast(*a)->f_index > (*b)->f_index
			&& ft_lstlast(*a)->f_index < (*a)->f_index)
		{
			rra(a);
		}
		else
			pa(b, a);
	}
}

void	sort_stack(int size, t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size < 32)
	{
		small_sort(a, b);
	}
	else
	{
		assign_index(*a, size);
		pb(a, b);
		pb(a, b);
		sort_to_b(a, b);
		sort_b(b);
		final_push_a(a, b);
		sort_a(a);
	}
}
