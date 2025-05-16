/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:19:09 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/13 18:01:14 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

void	free_height_map(t_data *data, int height)
{
	while (height != -1)
	{
		free(data->map[height]);
		height--;
	}
	free(data->map);
	data->map = NULL;
}

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

static void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_map(data);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}

int	close_app(t_data *data, bool	with_errors, bool all)
{
	if (with_errors)
		ft_show_error(data);
	if (all)
	{
		close(data->fd);
		free_data(data);
	}
	if (with_errors)
		return (1);
	else
		return (0);
}
