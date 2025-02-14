/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:38:09 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/14 05:30:27 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

char *find_executable(char **allpath, char *cmd) {
  int i;
  char *path_part;
  char *exec;

  i = 0;
  while (allpath[i]) {
    path_part = ft_strjoin(allpath[i], "/");
    if (!path_part) {
      ft_free_tab(allpath);
      exit(-1);
    }
    exec = ft_strjoin(path_part, cmd);
    free(path_part);
    if (!exec) {
      ft_free_tab(allpath);
      exit(-1);
    }
    if (access(exec, F_OK | X_OK) == 0) {
      ft_free_tab(allpath);
      return (exec);
    }
    free(exec);
    i++;
  }
  ft_free_tab(allpath);
  return (NULL);
}

char *my_getenv(char *name, char **env) {
  int i;
  int j;
  char *sub;

  i = 0;
  while (env[i]) {
    j = 0;
    while (env[i][j] && env[i][j] != '=') {
      j++;
    }
    sub = ft_substr(env[i], 0, j);
    if (ft_strcmp(sub, name) == 0) {
      free(sub);
      return (env[i] + j + 1);
    }
    free(sub);
    i++;
  }
  return (NULL);
}

char *get_path(char *cmd, char **env) {
  char *env_path;
  char **allpath;

  env_path = my_getenv("PATH", env);
  if (!env_path)
    return (NULL);
  allpath = ft_split(env_path, ':');
  if (!allpath)
    exit(-1);
  return (find_executable(allpath, cmd));
}

void exec(char *cmd, char **env) {
  char **s_cmd;
  char *path;

  s_cmd = ft_split(cmd, ' ');
  if (!s_cmd)
    exit(-1);
  path = get_path(s_cmd[0], env);
  if (!path) {
    ft_putstr_fd(s_cmd[0], 2);
    ft_putstr_fd(": command not found\n", 2);
    ft_free_tab(s_cmd);
    exit(127);
  }
  if (execve(path, s_cmd, env) == -1) {
    free(path);
    ft_free_tab(s_cmd);
    exit(1);
  }
}
