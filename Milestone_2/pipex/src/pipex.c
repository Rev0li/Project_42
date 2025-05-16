/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:43:57 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 10:15:19 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	child_1(char **av, int *p_fd, char **env);
void	child_2(char **av, int *p_fd, char **env);
void	execute_command(char *cmd, char **env);
int		wait_children(void);

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
		exit(EXIT_FAILURE);
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid < 0)
		cleanup(p_fd, -1);
	if (pid == 0)
		child_1(av, p_fd, env);
	pid = fork();
	if (pid < 0)
		cleanup(p_fd, -1);
	if (pid == 0)
		child_2(av, p_fd, env);
	if (close(p_fd[0]) == -1 || close(p_fd[1]) == -1)
		return (1);
	return (wait_children());
}

void	child_1(char **av, int *p_fd, char **env)
{
	int	fd;

	if (close(p_fd[0]) == -1)
		exit(1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		if (close(p_fd[1]) == -1)
			exit(1);
		perror(av[1]);
		exit (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(p_fd[1], STDOUT_FILENO) == -1)
	{
		if (close(fd) == -1)
			exit(1);
		if (close(p_fd[1]) == -1)
			exit(1);
		exit(1);
	}
	if (close(fd) == -1 || close(p_fd[1]) == -1)
		exit(1);
	execute_command(av[2], env);
}

void	child_2(char **av, int *p_fd, char **env)
{
	int	fd;

	if (close(p_fd[1]) == -1)
		exit(1);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		if (close(p_fd[0]) == -1)
			exit(1);
		perror(av[4]);
		exit (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1 || dup2(p_fd[0], STDIN_FILENO) == -1)
	{
		if (close(fd) == -1)
			exit(1);
		if (close(p_fd[0]) == -1)
			exit(1);
		exit(1);
	}
	if (close(fd) == -1 || close(p_fd[0]) == -1)
		exit(1);
	execute_command(av[3], env);
}

void	execute_command(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit(-1);
	path = get_cmd_path(s_cmd, env);
	if (!path)
	{
		ft_putstr_fd(s_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_tab(s_cmd, 0);
		exit(127);
	}
	check_permission(s_cmd, path);
	if (execve(path, s_cmd, env) == -1)
	{
		free(path);
		ft_free_tab(s_cmd, 0);
		exit(1);
	}
}

int	wait_children(void)
{
	int		status;
	pid_t	pid_exit;

	pid_exit = waitpid(-1, &status, 0);
	while (pid_exit > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit(WEXITSTATUS(status));
		pid_exit = waitpid(-1, &status, 0);
	}
	return (status);
}
