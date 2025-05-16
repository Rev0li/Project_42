/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:47:33 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 08:47:33 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"
#include "../../include/ft_xmalloc.h"

/***** itoa *****/
char	*ft_itoa(int n)
{
	char		*result;
	long int	ln;
	int			len;

	ln = n;
	len = get_int_size(n);
	result = (char *)ft_xmalloc((len + 1) * sizeof(char));
	if (!result)
	{
		write(2, "Error : Fail malloc ft_itoa\n", 28);
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
