/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:40:21 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/13 13:19:51 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;	

	a = NULL;
	b = NULL;
	if (check_init(ac, av, &a))
		return (display_error());
	sort_stack(ft_lstsize(a), &a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
