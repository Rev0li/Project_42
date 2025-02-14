/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:20:01 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/14 07:32:38 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void ft_free_tab(char **tab) {
  size_t i;

  i = 0;
  while (tab[i]) {
    free(tab[i]);
    i++;
  }
  free(tab);
}

void cleanup(int *p_fd, int exit_code) {
  if (p_fd[0] != -1)
    close(p_fd[0]);
  if (p_fd[1] != -1)
    close(p_fd[1]);
  exit(exit_code);
}
