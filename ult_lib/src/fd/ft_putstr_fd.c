/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:50:53 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:50:53 by okientzl         ###   ########.fr       */
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
