/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:18:30 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/18 10:56:46 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
// write(fd, s, ft_strlen(s));
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	printf("\n| Cas stdout          | ");
// 	fflush(stdout);
// 	ft_putstr_fd("Bonjour", 1);
//
// 	fprintf(stderr, "\n| Cas stderr          | ");
// 	fflush(stderr);
// 	ft_putstr_fd("Erreur", 2);
//
// 	int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		perror("\nErreur d'ouverture du fichier");
// 		printf("\n| Écriture fichier    | [FAIL] Erreur d'ouverture |\n");
// 	}
// 	else
// 	{
// 		ft_putstr_fd("Test d'écriture dans un fichier", fd);
// 		close(fd);
// 		printf("\n\"test_output.txt\" Contenu a vérifié |\n");
// 	}
// }
