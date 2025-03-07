/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:46:30 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/07 17:07:20 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static bool	init_app(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		data->error_code = 3;
		return (false);
	}
	make_title(data);
	if (!valid_map_file(data))
		return (false);
	if (data->height < 2 && data->min_width < 2)
	{
		data->error_code = 4;
		return (false);
	}
	data->window = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, data->title);
	if (!data->window)
	{
		data->error_code = 7;
		return (false);
	}
	data->img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	return (true);
}

static int	close_app(t_data *data, bool	with_errors, bool all)
{
	if (with_errors)
		ft_show_error(data);
	if (all)
	{
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
		close(data->fd);
		free_data(data);
	}
	if (with_errors)
		return (1);
	else
		return (0);
}

static	int	destroy_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_loop_end(data->mlx);
	close_app(data, false, true);
	exit(0);
	return (0);
}

static void	loop_app(t_data *data)
{
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	mlx_hook(data->window, 17, 0, destroy_hook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	data = NULL;
	if (argc == 2)
	{
		data = (t_data *)ft_calloc(1, sizeof(t_data));
		fd = openfile(argv[1], data);
		if (fd < 0)
			return (close_app(data, true, false));
		else
		{
			data->fd = fd;
			if (init_app(data))
			{
				loop_app(data);
				return (close_app(data, false, true));
			}
			else
				return (close_app(data, true, true));
		}
	}
	ft_print_error("Usage: ./fdf MAP_FILE", 1);
	return (1);
}
