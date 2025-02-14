/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:43:57 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/14 04:41:21 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	child_1(char **av, int *p_fd, char **env)
{
	int	fd;

	if (close(p_fd[0]) == -1)
		exit(1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		close(p_fd[1]);
		perror(av[1]);
		exit (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(p_fd[1], STDOUT_FILENO) == -1)
	{
		close(fd);
		close(p_fd[1]);
		exit(1);
	}
	if (close(fd) == -1 || close(p_fd[1]) == -1)
		exit(1);
	exec(av[2], env);
}

static void	child_2(char **av, int *p_fd, char **env)
{
	int	fd;

	if (close(p_fd[1]) == -1)
		exit(1);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		close(p_fd[0]);
		perror(av[4]);
		exit (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1 || dup2(p_fd[0], STDIN_FILENO) == -1)
	{
		close(fd);
		close(p_fd[0]);
		exit(1);
	}
	if (close(fd) == -1 || close(p_fd[0]) == -1)
		exit(1);
	exec(av[3], env);
}

void wait_children(void)
{
    int status;
    pid_t pid;

    while ((pid = waitpid(-1, &status, 0)) > 0)
    {
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            exit(WEXITSTATUS(status));
    }
}
int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	
	if (ac != 5)
		exit(-1);
	if (pipe(p_fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 < 0)
		cleanup(p_fd, -1);
	if (pid1 == 0)
		child_1(av, p_fd, env);
	pid2 = fork();
	if (pid2 < 0)
		cleanup(p_fd, -1);
	if (pid2 == 0)
		child_2(av, p_fd, env);
	if (close(p_fd[0]) == -1 || close(p_fd[1]) == -1 )
		return (1);
    wait_children();
	return (0);
}
