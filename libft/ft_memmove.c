/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:18:06 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/15 15:28:20 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
//     char src[] = "Hello, World!";
//     char dest[20] = {0};
//     ft_memmove(dest, src, 13);
//     if (strcmp(dest, src) == 0)
//         printf("Copie basique (sans chevauchement) [SUCCES]\n");
//     else
//         printf("Copie basique (sans chevauchement) [FAIL]\n");
//
//
//     char buffer1[] = "12345";
//     ft_memmove(buffer1 + 1, buffer1, 4);
//     if (strcmp(buffer1, "11234") == 0)
//         printf("Chevauchement avant [SUCCES]\n");
//     else
//         printf("Chevauchement avant [FAIL]\n");
//
//     char buffer2[] = "12345";
//     ft_memmove(buffer2, buffer2 + 1, 4);
//     if (strcmp(buffer2, "23455") == 0)
//         printf("Chevauchement arrière [SUCCES]\n");
//     else
//         printf("Chevauchement arrière [FAIL]\n");
//
//     char buffer3[] = "Test";
//     ft_memmove(buffer3, buffer3, 0);
//     if (strcmp(buffer3, "Test") == 0)
//         printf("Copie de 0 octets [SUCCES]\n");
//     else
//         printf("Copie de 0 octets [FAIL]\n");
// }
