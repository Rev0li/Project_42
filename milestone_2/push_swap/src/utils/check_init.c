/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:18:26 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 12:12:07 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	has_duplicates(int ac, char **av)
{
	int	i;
	int	j;
	int	num_i;
	int	num_j;

	i = 1;
	while (i < ac -1)
	{
		j = i + 1;
		while (j < ac)
		{
			num_i = ft_atoi(av[i]);
			num_j = ft_atoi(av[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]) || is_integer(av[i]))
			return (1);
		i++;
	}
	if (has_duplicates(ac, av))
		return (1);
	return (0);
}

int	check_init(int ac, char **av, t_stack **a)
{
	if (ac < 2)
		return (1);
	if (check_arg(ac, av))
		return (1);
	if (init_stack(ac, av, a))
		return (1);
	return (0);
}
