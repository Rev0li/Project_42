/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:48:02 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 16:18:03 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	printf("| Cas stdout          | ");
// 	fflush(stdout);
// 	ft_putendl_fd("Bonjour", 1);
//
// 	fprintf(stderr, "| Cas stderr          | ");
// 	fflush(stderr);
// 	ft_putendl_fd("Erreur", 2);
//
// 	int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		perror("Erreur d'ouverture du fichier");
// 		printf("| Écriture fichier    | [FAIL] Erreur d'ouverture |\n");
// 	}
// 	else
// 	{
// 		ft_putendl_fd("Test d'écriture dans un fichier", fd);
// 		close(fd);
// 		printf("| Écriture fichier  \"test_output.txt\" Contenu a vérifié |\n");
// 	}
// }
