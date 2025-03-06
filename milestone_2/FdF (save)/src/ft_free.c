/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:19:09 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/01 15:19:50 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data || !data->map)
		return ;
	while (i < data->height)
	{
		if (data->map[i])
			free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

void	free_token(char **tab)
{
	size_t	i;

	if (!tab)
	{
		ft_printf("ft_free_tab : tab NULL !\n");
		return ;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_map(data);
	if (data->title)
	{
		free(data->title);
		data->title = NULL;
	}
	free(data->mlx);
	free(data);
}
