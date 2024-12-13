/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:24:28 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/10 16:46:30 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ult_lib.h"

/***** itoa *****/
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
	char		*result;
	long int	ln;
	int			len;

	ln = n;
	len = get_size(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
	{
		ft_printf("Erreur : échec de l'allocation mémoire dans ft_itoa\n");
		return (NULL);
	}
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

/***** tolower *****/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

/***** toupper *****/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
