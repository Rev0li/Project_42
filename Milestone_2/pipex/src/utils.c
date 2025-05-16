/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:38:09 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/26 14:04:16 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

int		is_path_absolute_or_relative(char *cmd);
char	*get_path(char **cmd, char **env);
char	*my_getenv(char *name, char **env);
char	*find_executable(char **allpath, char **cmd);

char	*get_cmd_path(char **s_cmd, char **env)
{
	int		abs_path;
	char	*tmp;
	char	*path;

	abs_path = is_path_absolute_or_relative(s_cmd[0]);
	tmp = NULL;
	path = NULL;
	if (abs_path)
	{
		if (access(s_cmd[0], F_OK) == 0)
			tmp = ft_strdup(s_cmd[0]);
		return (tmp);
	}
	path = get_path(s_cmd, env);
	return (path);
}

int	is_path_absolute_or_relative(char *cmd)
{
	int	len;

	len = 0;
	if (!cmd)
		return (0);
	if (cmd[0] == '/')
		return (1);
	if (cmd[0] == '.' && cmd[1] == '/')
		return (1);
	if (cmd[0] == '.')
	{
		if (cmd[1] == '.' && cmd[2] == '/')
			return (1);
	}
	return (0);
}

char	*get_path(char **cmd, char **env)
{
	char	*env_path;
	char	**allpath;
	char	*exec;

	env_path = my_getenv("PATH", env);
	if (!env_path)
		return (NULL);
	allpath = ft_split(env_path, ':');
	if (!allpath)
		exit(-1);
	exec = find_executable(allpath, cmd);
	return (exec);
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

char	*find_executable(char **allpath, char **cmd)
{
	int		i;
	char	*path_part;
	char	*exec;

	i = 0;
	while (allpath[i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		if (!path_part)
			ft_free_double_tab(allpath, cmd);
		exec = ft_strjoin(path_part, cmd[0]);
		free(path_part);
		if (!exec)
			ft_free_double_tab(allpath, cmd);
		if (access(exec, F_OK) == 0)
		{
			ft_free_tab(allpath, 0);
			return (exec);
		}
		free(exec);
		i++;
	}
	ft_free_tab(allpath, 0);
	return (NULL);
}
