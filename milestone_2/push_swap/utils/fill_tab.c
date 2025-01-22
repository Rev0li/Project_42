/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:01:11 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/21 15:30:00 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static char	*my_strdup(const char *s)
{
	char	*copy;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**fill_tab(int argc, char **argv)
{
	char	**result;
	int		i;

	result = (char **)malloc((argc) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		result[i] = my_strdup(argv[i + 1]);
		if (!result[i])
			return (free_arg(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}
