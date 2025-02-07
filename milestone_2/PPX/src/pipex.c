/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:43:57 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/07 14:58:13 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	(void)cmd;
	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit(-1);
	path = get_path(s_cmd[0], env);
	if (!path)
	{
		ft_putstr_fd(s_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_tab(s_cmd);
		exit(-1);
	}
	if (execve(path, s_cmd, env) == -1)
	{
		free(path);
		ft_free_tab(s_cmd);
		exit(-1);
	}
}

void clos_ex(int *p_fd)
{
		close(p_fd[0]);
		close(p_fd[1]);
		ft_printf("close_ex");
		exit(-1);
}

void	child_1(char **av, int *p_fd, char **env)
{
	int	fd;

	close(p_fd[0]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		close(p_fd[1]);
		perror(av[1]);
		exit (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(p_fd[1], STDOUT_FILENO) == -1)
	{
		close(fd);
		close(p_fd[1]);
		exit(-1);
	}
	close(fd);
	close(p_fd[1]);
	exec(av[2], env);
	(void)env;
}

static void	child_2(char **av, int *p_fd, char **env)
{
	int	fd;

	close(p_fd[1]);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		close(p_fd[0]);
		perror(av[4]);
		exit (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1 || dup2(p_fd[0], STDIN_FILENO) == -1)
	{
		close(fd);
		close(p_fd[0]);
		exit(-1);
	}
	close(fd);
	close(p_fd[0]);
	exec(av[3], env);
	(void)env;
}


int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (ac != 5)
		exit(1);
	if (pipe(p_fd) == -1)
		exit(1);
	pid1 = fork();
	if (pid1 < 0)
		clos_ex(p_fd);
	if (pid1 == 0)
		child_1(av, p_fd, env);
	pid2 = fork();
	if (pid2 < 0)
		clos_ex(p_fd);
	if (pid2 == 0)
		child_2(av, p_fd, env);

	close(p_fd[0]);
	close(p_fd[1]);

   waitpid(pid1, &status1, 0);
   if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0) 
       exit(WEXITSTATUS(status1));

   waitpid(pid2, &status2, 0);
   if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0)
       exit(WEXITSTATUS(status2));
	return (0);
}
