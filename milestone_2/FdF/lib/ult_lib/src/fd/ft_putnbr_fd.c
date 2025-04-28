/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:11:16 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/27 18:11:16 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** putnbr_fd *****/
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) == -1)
			write(2, "Err: Fail write MIN_INT in ft_putnbr_fd\n", 40);
		return ;
	}
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
		{
			write(2, "Err: Fail write '-' in ft_putnbr_fd\n", 36);
			return ;
		}
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	if (write(fd, &c, 1) == -1)
		write(2, "Err: Fail write nbr in ft_putnbr_fd\n", 36);
}
