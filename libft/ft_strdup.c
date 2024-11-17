/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:31:41 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/17 13:14:19 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*copy;

	i = 0;
	len = ft_strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (i <= len)
	{
		copy[i] = s[i];
		i++;
	}
	return (copy);
}
// #include <string.h>
// #include <stdio.h>
//
// int	ft_strlen(const char *string)
// {
// 	int	i;
//
// 	i = 0;
// 	while (string[i] != '\0')
// 		i++;
// 	return (i);
// }
//
//
// int	main()
// {
//     const char *str1 = "Hello World";
//     char *dup1 = ft_strdup(str1);
//     if (strcmp(dup1, str1) == 0)
//         printf("Dupliquer chaîne non vide | [SUCCÈS]");
//     else
//         printf("Dupliquer chaîne non vide | [ÉCHOUÉ]");
//     free(dup1);
//
//     const char *str2 = "";
//     char *dup2 = ft_strdup(str2);
//     if (strcmp(dup2, str2) == 0)
//         printf("Dupliquer chaîne vide | [SUCCÈS]");
//     else
//         printf("Dupliquer chaîne vide | [ÉCHOUÉ]");
//     free(dup2);
// }
