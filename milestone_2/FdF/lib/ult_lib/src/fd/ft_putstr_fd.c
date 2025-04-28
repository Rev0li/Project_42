/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:14:36 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 18:16:22 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** putstr_fd *****/
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		write(2, "Error : pointer NULL in ft_putstr_fd\n", 37);
		return ;
	}
	if (write(fd, s, ft_strlen(s)) == -1)
	{
		write(2, "Error : Fail write in ft_putstr_fd\n", 35);
		return ;
	}
}
