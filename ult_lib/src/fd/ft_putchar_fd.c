/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:50:02 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:50:02 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** putchar_fd *****/
void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		write(2, "Err: Fail write in ft_putchar_fd\n", 33);
}
