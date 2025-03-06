/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:23:48 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/06 11:59:15 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

t_coord	project_iso(t_coord pt, int scale)
{
	t_coord	new;

	new.x = (int)((pt.x * scale - pt.y * scale) * cos(ISO_ANGLE));
	new.y = (int)((pt.x * scale + pt.y * scale) * sin(ISO_ANGLE)) - pt.z * scale;
	new.z = 0;
	new.special = pt.special;
	new.end = pt.end;
	new.color = pt.color;
	return (new);
}

t_line_params	assign_struct_line(t_coord p0, t_coord p1, t_transform *transform)
{
	t_line_params	params;

	params.x0 = p0.x + transform->x_off;
	params.y0 = p0.y + transform->y_off;
	params.x1 = p1.x + transform->x_off;
	params.y1 = p1.y + transform->y_off;
	params.dx = abs(params.x1 - params.x0);
	params.dy = abs(params.y1 - params.y0);
	if (params.x0 < params.x1)
		params.sx = 1;
	else
		params.sx = -1;
	if (params.y0 < params.y1)
		params.sy = 1;
	else
		params.sy = -1;
	params.err = params.dx - params.dy;
	params.e2 = 0;
	return (params);
}

void	draw_line(t_data *data, t_coord p0, t_coord p1, t_transform *transform)
{
	t_line_params	params;

	params = assign_struct_line(p0, p1, transform);
	while (1)
	{
		mlx_pixel_put(data->mlx, data->window, params.x0, params.y0, p0.color);
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

static void	draw_map_row(t_data *data, int row, t_transform *transform, int row_len)
{
	int		j;
	int		next_len;
	t_coord	p0;
	t_coord	p1;

	j = 0;
	while (j < row_len)
	{
		p0 = project_iso(data->map[row][j], data->scale);
		if (!data->map[row][j].end)
		{
			p1 = project_iso(data->map[row][j + 1], data->scale);
			draw_line(data, p0, p1, transform);
		}
		if (row < data->height - 1)
		{
			next_len = get_row_length(data->map[row + 1]);
			if (j < next_len)
			{
				p1 = project_iso(data->map[row + 1][j], data->scale);
				draw_line(data, p0, p1, transform);
			}
		}
		j++;
	}
}

void	draw_map(t_data *data)
{
	int			i;
	int			row_len;
	t_transform transform;

	data->scale = compute_scale(data) / 2;
    transform.x_off = W_WIDTH / 2;
    transform.y_off = W_HEIGHT / 4;
	i = 0;
	while (i < data->height)
	{
		row_len = get_row_length(data->map[i]);
		draw_map_row(data, i, &transform, row_len);
		i++;
	}
}
