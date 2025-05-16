/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:23:10 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/26 09:44:18 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include "../lib/ult_lib/ult_lib.h"

void	check_permission(char **s_cmd, char *path);
char	*get_cmd_path(char **s_cmd, char **env);
void	execute_command(char *cmd, char **env);
void	ft_free_tab(char **tab, int out_or_not);
void	cleanup(int *p_fd, int exit_code);
void	ft_free_double_tab(char **tab, char **tab_2);

#endif
