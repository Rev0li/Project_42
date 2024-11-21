/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:31:04 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/18 10:42:48 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*result;
	long int		ln;
	int				len;

	ln = n;
	len = get_size(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (ln < 0)
		ln = -ln;
	while (len--)
	{
		result[len] = ln % 10 + '0';
		ln = ln / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	int list[] = {
// 		0,
// 		123456,
// 		-123,
// 		-2147483648,
// 		2147483647
// 	};
// 	if (!strcmp(ft_itoa(list[0]),"0"))
// 		printf("%20d  [SUCCES]\n", list[0]);
// 	else
// 		printf("%20d [FAIL]\n", list[0]);
//
// 	if (!strcmp(ft_itoa(list[1]),"123456"))
// 		printf("%20d  [SUCCES]\n", list[1]);
// 	else
// 		printf("%20d [FAIL]\n", list[1]);
//
// 	if (!strcmp(ft_itoa(list[2]),"-123"))
// 		printf("%20d  [SUCCES]\n", list[2]);
// 	else
// 		printf("%20d [FAIL]\n", list[2]);
//
// 	if (!strcmp(ft_itoa(list[3]),"-2147483648"))
// 		printf("%20d  [SUCCES]\n", list[3]);
// 	else
// 		printf("%20d [FAIL]\n", list[3]);
//
// 	if (!strcmp(ft_itoa(list[4]),"2147483647"))
// 		printf("%20d  [SUCCES]\n", list[4]);
// 	else
// 		printf("%20d [FAIL]\n", list[4]);
// }
