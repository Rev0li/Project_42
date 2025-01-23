/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:16:11 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:04:22 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ult_lib.h"

/***** putchar_fd *****/
void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		ft_printf("Err: échec de l'écriture dans ft_putchar_fd\n");
}

/***** putendl_fd *****/
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_putendl_fd\n");
		return ;
	}
	while (*s)
	{
		if (write(fd, s, 1) == -1)
		{
			ft_printf("Erreur : échec de l'écriture dans ft_putendl_fd\n");
			return ;
		}
		s++;
	}
	if (write(fd, "\n", 1) == -1)
		ft_printf("Err: échec écriture saut de ligne dans ft_putendl_fd\n");
}

/***** putnbr_fd *****/
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) == -1)
			ft_printf("Err: échec écriture MIN_INT dans ft_putnbr_fd\n");
		return ;
	}
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
		{
			ft_printf("Err: échec écriture du signe '-' dans ft_putnbr_fd\n");
			return ;
		}
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	if (write(fd, &c, 1) == -1)
		ft_printf("Err: échec écriture du chiffre dans ft_putnbr_fd\n");
}

/***** putstr_fd *****/
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		ft_printf("Erreur : pointeur NULL passé à ft_putstr_fd\n");
		return ;
	}
	while (*s)
	{
		if (write(fd, s, 1) == -1)
		{
			ft_printf("Erreur : échec de l'écriture dans ft_putstr_fd\n");
			return ;
		}
		s++;
	}
}
