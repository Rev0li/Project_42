/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:17:23 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/14 11:40:46 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->z_scale += 0.1;
	else if (button == 5)
	{
		data->z_scale -= 0.1;
	}
	mlx_destroy_image(data->mlx, data->img.img);
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
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		destroy_hook(data);
	return (0);
}

int	destroy_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_loop_end(data->mlx);
	close_app(data, false, true);
	exit(0);
	return (0);
}

bool	openfile(char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		data->error_message = strerror(errno);
		data->error_code = 2;
		return (false);
	}
	data->file_name = filename;
	data->fd = fd;
	return (true);
}
