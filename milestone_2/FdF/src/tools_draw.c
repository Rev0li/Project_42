/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:17 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/12 14:46:17 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

int	ft_hextoint(const char *hex)
{
	int	result;
	int	i;
	int	digit;

	result = 0;
	i = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i += 2;
	else if (hex[0] == '#')
		i++;
	while (hex[i])
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			digit = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			digit = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			digit = hex[i] - 'A' + 10;
		result = result * 16 + digit;
		i++;
	}
	return (result);
}

int	get_row_length(t_coord *row)
{
	int	len;

	len = 0;
	while (!row[len].end)
		len++;
	return (len + 1);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.line_length + x
			* (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_coord	project_iso(t_coord pt, double scale, double z_scale)
{
	t_coord	new;

	new.x = (int)((pt.x * scale - pt.y * scale) * cos(ISO_AGL));
	new.y = (int)((pt.x * scale + pt.y * scale) * sin(ISO_AGL))
		- pt.z * scale * z_scale;
	new.z = 0;
	new.special = pt.special;
	new.end = pt.end;
	new.color = pt.color;
	return (new);
}

t_line_params	assign_struct_line(t_coord p0, t_coord p1, t_data *data)
{
	t_line_params	params;

	params.x0 = p0.x + data->x_off;
	params.y0 = p0.y + data->y_off;
	params.x1 = p1.x + data->x_off;
	params.y1 = p1.y + data->y_off;
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
