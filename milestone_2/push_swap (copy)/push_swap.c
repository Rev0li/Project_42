/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:40:21 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/20 16:43:33 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	**a = NULL;
	//t_stack **b;
	t_stack *new_node;
	size_t	i;

	i = 1;
	if (check_arg(argc, argv))
		return (display_error());
	while (i < (size_t)argc)
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		if (!new_node)
		{
			display_error();
			return (1);
		}
		ft_lstadd_back(a, new_node);
		i++;
	}
	ft_lstiter(*a);

	return (0);
}
