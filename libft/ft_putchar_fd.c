/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:40:57 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 16:19:07 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
//     printf("| Cas stdout          | ");
// 	fflush(stdout);
//     ft_putchar_fd('A', 1);
// 	printf(" <- vérifiez la sortie | [SUCCES] ou [FAIL]\n");
//
//     fprintf(stderr, "| Cas stderr          | ");
//     ft_putchar_fd('B', 2);
// 	fprintf(stderr, " <- vérifiez la sortie | [SUCCES] ou [FAIL]\n");
//
//     int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd == -1)
//     {
//         perror("Erreur d'ouverture du fichier");
//         printf("| Écriture fichier    | [FAIL] Erreur d'ouverture |\n");
//     }
//     else
//     {
//         ft_putchar_fd('C', fd);
//         close(fd);
//         printf("| \"test_output.txt\"Contenu a vérifié |\n");
// 	}
// }
