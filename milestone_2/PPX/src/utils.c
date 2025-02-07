/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:38:09 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/07 15:56:37 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	*env_path;

	env_path = my_getenv("PATH", env);
	if (!env_path)
		return (NULL);
	allpath = ft_split(env_path, ':');
	if (!allpath)
		exit(-1);
	i = 0;
	while (allpath[i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		if (!path_part)
		{
			ft_free_tab(allpath);
			exit(-1);
		}
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (!exec)
		{
			ft_free_tab(allpath);
			exit(-1);
		}
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(allpath);
			return (exec);
		}
		free(exec);
		i++;
	}
	ft_free_tab(allpath);
	return (NULL);
}
