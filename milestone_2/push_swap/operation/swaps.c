/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:38:11 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/16 18:38:17 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <unistd.h>

void sa(t_stack **a)
{
    t_stack *first;
    t_stack *second;

    if (!*a || !(*a)->next)
        return ;
    first = *a;
    second = (*a)->next;
    first->next = second->next;
    second->next = first;
    *a = second;
	write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
    t_stack *first;
    t_stack *second;

    if (!*b || !(*b)->next)
        return ;
    first = *b;
    second = (*b)->next;
    first->next = second->next;
    second->next = first;
    *b = second;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*a_first;
	t_stack	*a_second;
	t_stack	*b_first;
	t_stack	*b_second;

	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	a_first = *a;
	b_first = *b;
	a_second = (*a)->next;
	b_second = (*b)->next;
	a_first->next = a_second->next;
	b_first->next = b_second->next;
	a_second->next = a_first;
	b_second->next = b_first;
	*a = a_second;
	*b = b_second;
	write(1, "ss\n", 3);
}
