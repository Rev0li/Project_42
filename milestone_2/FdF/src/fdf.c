/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:46:30 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/25 01:26:06 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static bool	init_app_2(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (!data->img.img)
	{
		data->error_code = 7;
		return (false);
	}
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
	{
		data->error_code = 7;
		return (false);
	}
	return (true);
}

static bool	init_app(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		data->error_code = 7;
		return (false);
	}
	data->window = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT,
			data->file_name);
	if (!data->window)
	{
		data->error_code = 7;
		return (false);
	}
	if (!init_app_2(data))
		return (false);
	return (true);
}

static void	loop_app(t_data *data)
{
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	mlx_hook(data->window, 2, 1L << 0, key_hook, data);
	mlx_hook(data->window, 17, 0, destroy_hook, data);
	mlx_mouse_hook(data->window, mouse_hook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc == 2)
	{
		data = (t_data *)ft_calloc(1, sizeof(t_data));
		if (!openfile(argv[1], data))
			return (close_app(data, true, true));
		if (init_app(data))
		{
			if (!valid_map_file(data))
				return (close_app(data, true, true));
			loop_app(data);
			return (close_app(data, false, true));
		}
		else
			return (close_app(data, true, true));
	}
	ft_print_error("Usage: ./fdf MAP_FILE", 1);
	return (1);
}
