/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:21:44 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/04 13:35:28 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	exit_handler(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	else if (n_exit == 2)
		ft_putstr_fd("Failure alloc memory\n", 2);
	else if (n_exit == 3)
		ft_putstr_fd("Failure open file\n", 2);
	else if (n_exit == 4)
		ft_putstr_fd("Failure dup2\n", 2);
	else if (n_exit == 5)
		ft_putstr_fd("Failure pipe\n", 2);
	else if (n_exit == 6)
		ft_putstr_fd("Failure fork\n", 2);
	else if (n_exit == 7)
		ft_putstr_fd("command not foundXXX\n", 2);
	else if (n_exit == 8)
		ft_putstr_fd("execution failed\n", 2);
	exit(-1);
}

int	open_file(char *file, int in_or_out)
{ 
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY);
	else if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		ret = -1;
	if (ret == -1)
		exit_handler(3);
	return (ret);
}

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
		exit_handler(2);
	i = 0;
	while (allpath[i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		if (!path_part)
		{
			ft_free_tab(allpath);
			exit_handler(2);
		}
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (!exec)
		{
			ft_free_tab(allpath);
			exit_handler(2);
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
