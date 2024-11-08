/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:16:11 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 18:12:05 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
	int	i = 0;
	int	sign = 1;
	int	result = 0;

	// Ignorer les espaces blancs initiaux
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;

	// Gérer les signes
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// Conversion des chiffres en entier
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return result * sign;
}

