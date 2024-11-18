/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:16:11 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/18 11:54:19 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	char *list[] = {
// 		"12345",
// 		"      123456",
// 		"   -123",
// 		"   ++1",
// 		"  --1","0",
// 		"-2147483648",
// 		"2147483647",
// 		"",
// 		"\t \n \v \f \r",
// 		"010",
// 		"123a4",
// 		"-9223372036854775807",
// 		NULL
// 	};
// 	int	i = 0;
// 	while (list[i] != NULL)
// 	{
// 		if (ft_atoi(*list) == atoi(*list))
// 			printf("%20s  [SUCCES]\n", list[i]);
// 		else
// 			printf("%20s [FAIL]\n", list[i]);
// 		i++;
// 	}
// }
