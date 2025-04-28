/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:23:48 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/13 18:29:05 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

void	draw_line(t_data *data, t_coord p0, t_coord p1)
{
	t_line_params	params;

	params = assign_struct_line(p0, p1, data);
	while (1)
	{
		put_pixel(data, params.x0, params.y0, p0.color);
		if (params.x0 == params.x1 && params.y0 == params.y1)
			break ;
		params.e2 = 2 * params.err;
		if (params.e2 > -params.dy)
		{
			params.err -= params.dy;
			params.x0 += params.sx;
		}
		if (params.e2 < params.dx)
		{
			params.err += params.dx;
			params.y0 += params.sy;
		}
	}
}

static void	draw_horizontal_segment(t_data *data, int row, int col, int row_len)
{
	t_coord	p0;
	t_coord	p1;

	p0 = project_iso(data->map[row][col], data->scale, data->z_scale);
	if (col + 1 < row_len)
	{
		p1 = project_iso(data->map[row][col + 1], data->scale, data->z_scale);
		draw_line(data, p0, p1);
	}
}

static void	draw_vertical_segment(t_data *data, int row, int col)
{
	t_coord	p0;
	t_coord	p1;
	int		next_len;

	p0 = project_iso(data->map[row][col], data->scale, data->z_scale);
	next_len = get_row_length(data->map[row + 1]);
	if (col < next_len)
	{
		p1 = project_iso(data->map[row + 1][col], data->scale, data->z_scale);
		draw_line(data, p0, p1);
	}
}

static void	draw_map_row(t_data *data, int row, int row_len)
{
	int	j;

	j = 0;
	while (j < row_len)
	{
		draw_horizontal_segment(data, row, j, row_len);
		if (row < data->height - 1)
			draw_vertical_segment(data, row, j);
		j++;
	}
}

void	draw_map(t_data *data)
{
	int			i;
	int			row_len;

	compute_scale(data);
	data->x_off = W_WIDTH / 2;
	data->y_off = W_HEIGHT / 2;
	i = 0;
	while (i < data->height)
	{
		row_len = get_row_length(data->map[i]);
		draw_map_row(data, i, row_len);
		i++;
	}
}
