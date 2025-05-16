/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:50:22 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:50:22 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** putendl_fd *****/
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
	{
		write(2, "Error : pointer NULL in ft_putendl_fd\n", 38);
		return ;
	}
	if (write(fd, s, ft_strlen(s)) == -1)
	{
		write(2, "Error : Fail write in ft_putendl_fd\n", 36);
		return ;
	}
	if (write(fd, "\n", 1) == -1)
		write(2, "Err: Fail write in ft_putendl_fd\n", 33);
}
