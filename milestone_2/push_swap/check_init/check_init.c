/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:18:26 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/21 10:28:57 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

/*int	checker()*/
/*{*/
/*	if ()*/
/*		return (1);*/
/*	return (0);*/
/*}*/

char	**fill_arg(char **tab_arg, int ac, char **av, int *nb_arg)
{
	if (ac == 2)
	{
		tab_arg = ft_split(av[1], ' ', nb_arg);
		return (tab_arg);
	}
	else if (ac > 2)
	{
		*nb_arg = ac - 1;
		tab_arg = fill_tab(ac, av);
		return (tab_arg);
	}
	return (NULL);
}

int	check_init(int argc, char **argv, t_stack **a)
{
	char	**tab_arg;
	int		nb_arg;

	tab_arg = NULL;
	if (argc < 2)
		return (1);
	tab_arg = fill_arg(tab_arg, argc, argv, &nb_arg);
	if (tab_arg == NULL)
		return (1);
	if (check_arg(nb_arg, tab_arg))
	{
		free_arg(tab_arg, nb_arg);
		return (1);
	}
	if (init_stack(nb_arg, tab_arg, a))
	{
		free_arg(tab_arg, nb_arg);
		return (1);
	}
	free_arg(tab_arg, nb_arg);
	return (0);
}
