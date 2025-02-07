/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:48:03 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/04 17:33:04 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit_handler(2);
	path = get_path(s_cmd[0], env);
	if (!path)
	{
		//ft_putstr_fd("pipex: command not found: ", 2);
		//ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit_handler(7);
	}
	if (execve(path, s_cmd, env) == -1)
	{
		//ft_putstr_fd("pipex: execution failed: ", 2);
		//ft_putendl_fd(s_cmd[0], 2);
		free(path);
		ft_free_tab(s_cmd);
		exit_handler(8);
	}
}

static void	child_1(char **av, int *p_fd, char **env)
{
	int	fd;

	close(p_fd[0]);
	fd = open_file(av[1], 0);
	if (fd == -1)
		exit(0);
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(p_fd[1], STDOUT_FILENO) == -1)
	{
		close(fd);
		close(p_fd[1]);
		exit_handler(4);
	}
	close(fd);
	close(p_fd[1]);
	exec(av[2], env);
}

static void	child_2(char **av, int *p_fd, char **env)
{
	int	fd;

	close(p_fd[1]);
	fd = open_file(av[4], 1);
		if (fd == -1)
		exit(0);
	if (dup2(fd, STDOUT_FILENO) == -1 || dup2(p_fd[0], STDIN_FILENO) == -1)
	{
		close(fd);
		close(p_fd[0]);
		exit_handler(4);
	}
	close(fd);
	close(p_fd[0]);
	exec(av[3], env);
}


int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid1, pid2;
	int		status1, status2;

	if (ac != 5)
		exit_handler(1);
	if (pipe(p_fd) == -1)
		exit_handler(5);

	pid1 = fork();
	if (pid1 < 0)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		exit_handler(6);
	}
	if (pid1 == 0)
		child_1(av, p_fd, env);

	pid2 = fork();
	if (pid2 < 0)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		exit_handler(6);
	}
	if (pid2 == 0)
		child_2(av, p_fd, env);
	

	close(p_fd[0]);
	close(p_fd[1]);

    waitpid(pid1, &status1, 0);
    if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0)
    {
        exit(WEXITSTATUS(status1));
    }
    waitpid(pid2, &status2, 0);
    if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0)
    {
        exit(WEXITSTATUS(status2));
    }

	return (0);
}
