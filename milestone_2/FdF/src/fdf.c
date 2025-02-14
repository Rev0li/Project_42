/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:46:30 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/13 18:19:23 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static bool	init_app(t_data *data, int fd)
{
	data->fd = fd;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		data->error_code = 3;
		return (false);
	}
	make_title(data);
	/*if (!read_map_file(data))*/
	/*	return (false);*/
	/*data->map = make_map(data);*/
	/*if (data->file_x < 2 && data->file_y < 2)*/
	/*	return (false);*/
	data->window = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, data->title);
	/*if (!data->window || !ft_init_image(data))*/
	/*{*/
	/*	data->error_code = 7;*/
	/*	return (false);*/
	/*}*/
	return (true);
}

static int	close_app(t_data *data, bool	with_errors, bool all)
{
	if (with_errors)
		ft_show_error(data);
	if (all)
	{
		/*ft_free_file_stack(data->file_map);*/
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
		/*if (data->map)*/
		/*	ft_free_map(data->map, data->file_y);*/
		/*free(data->mlx_img);*/
		free(data->title);
	}
	free(data);
	if (with_errors)
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
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
			if (init_app(data, fd))
			{
				ft_printf("Hello in app\n");
				mlx_loop(data->mlx);

				/*loop_app(data);*/
				return (close_app(data, false, true));
			}
			else
				return (close_app(data, true, true));
		}
	}
	ft_print_error("Usage: ./fdf MAP_FILE", 1);
	return (1);
}
