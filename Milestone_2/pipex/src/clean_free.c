/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:20:01 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/18 12:15:34 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	check_permission(char **s_cmd, char *path)
{
	if (access(path, X_OK) != 0)
	{
		ft_putstr_fd(s_cmd[0], 2);
		ft_putstr_fd(": permission denied\n", 2);
		free(path);
		ft_free_tab(s_cmd, 0);
		exit(126);
	}
}

void	ft_free_tab(char **tab, int out_or_not)
{
	size_t	i;

	if (!tab)
	{
		ft_printf("ft_free_tab : tab NULL !\n");
		return ;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	if (out_or_not == 1)
	{
		exit (EXIT_FAILURE);
	}
}

void	ft_free_double_tab(char **tab, char **tab_2)
{
	size_t	i;

	if (!tab || !tab_2)
	{
		ft_printf("ft_free_tab : tab NULL !\n");
		return ;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	i = 0;
	while (tab_2[i])
	{
		free(tab_2[i]);
		i++;
	}
	free(tab_2);
	exit (EXIT_FAILURE);
}

void	cleanup(int *p_fd, int exit_code)
{
	if (!p_fd)
	{
		ft_printf("Cleanup : p_fd NULL\n");
		exit(exit_code);
	}
	if (p_fd[0] != -1)
	{
		if (close(p_fd[0]) == -1)
		{
			ft_printf("FAIL CLOSE !\n");
			exit(1);
		}
	}
	if (p_fd[1] != -1)
	{
		if (close(p_fd[1]) == -1)
		{
			ft_printf("FAIL CLOSE !\n");
			exit (1);
		}
	}
	exit(exit_code);
}
