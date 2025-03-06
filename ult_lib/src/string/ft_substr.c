/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:44:29 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/02 14:05:04 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/ult_lib.h"

/***** substr *****/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;

	if (!s)
	{
		write(2, "Error : pointer NULL in ft_substr\n", 34);
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
	{
		write(2, "Error : Fail malloc in ft_substr\n", 33);
		return (NULL);
	}
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}
