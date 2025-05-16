/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:06:05 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 09:06:05 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** strmapi *****/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
	{
		write(2, "Error : pointer NULL in ft_strmapi\n", 35);
		return (NULL);
	}
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
	{
		write(2, "Error : Fail malloc in ft_strmapi\n", 34);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
