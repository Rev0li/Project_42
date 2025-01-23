/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:55:52 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/22 14:05:43 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ult_lib.h"

/***** isalpha *****/
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/***** isdigit *****/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

//***** isalnum *****/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/***** isascii *****/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/***** isprint *****/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
