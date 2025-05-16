/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:00:05 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 12:16:11 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static int	find_min_pos(t_stack *a)
{
	int		min;
	int		pos;
	int		i;
	t_stack	*current;

	min = a->value;
	pos = 0;
	i = 0;
	current = a;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

static int	sort_to_three(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;
	int	nbr_pb;

	nbr_pb = 0;
	while (ft_lstsize(*a) > 3)
	{
		size = ft_lstsize(*a);
		min_pos = find_min_pos(*a);
		if (min_pos == 0)
		{
			nbr_pb ++;
			pb(a, b);
		}
		else if (min_pos <= size / 2)
			while (min_pos-- > 0)
				ra(a);
		else
		{
			min_pos = size - min_pos;
			while (min_pos-- > 0)
				rra(a);
		}
	}
	return (nbr_pb);
}

static void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	nbr_pb;

	nbr_pb = sort_to_three(a, b);
	sort_three(a);
	while (nbr_pb-- != 0)
		pa(b, a);
}
