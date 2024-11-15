/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:57:35 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 16:47:39 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
//     printf("| Cas stdout (42)     | ");
//     fflush(stdout);
//     ft_putnbr_fd(42, 1);
//     printf(" <- vérifiez la sortie\n");
//
//     printf("| Cas stdout (0)      | ");
//     fflush(stdout);
//     ft_putnbr_fd(0, 1);
//     printf(" <- vérifiez la sortie\n");
//
//     printf("| Cas stdout (-1234)  | ");
//     fflush(stdout);
//     ft_putnbr_fd(-1234, 1);
//     printf(" <- vérifiez la sortie\n");
//
//     printf("| Cas stdout (INT_MIN)| ");
//     fflush(stdout);
//     ft_putnbr_fd(-2147483648, 1);
//     printf(" <- vérifiez la sortie\n");
//
//     printf("| Cas stdout (INT_MAX)| ");
//     fflush(stdout);
//     ft_putnbr_fd(2147483647, 1);
//     printf(" <- vérifiez la sortie\n");
//
//     int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd == -1)
//     {
//         perror("Erreur d'ouverture du fichier");
//         printf("| Écriture fichier    | [ÉCHOUÉ] Erreur d'ouverture |\n");
//     }
//     else
//     {
//         ft_putnbr_fd(123456789, fd);
//         close(fd);
//         printf("\"test_output.txt\" Contenu a vérifié |\n");
//     }
// }
