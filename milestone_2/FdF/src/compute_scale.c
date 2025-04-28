/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:31:52 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/13 19:36:21 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static void	update_bbox_values(t_coord p, t_bbox *bbox)
{
	if (p.x < bbox->min_x)
		bbox->min_x = p.x;
	if (p.x > bbox->max_x)
		bbox->max_x = p.x;
	if (p.y < bbox->min_y)
		bbox->min_y = p.y;
	if (p.y > bbox->max_y)
		bbox->max_y = p.y;
}

static void	process_bbox_row(t_data *data, int row, t_bbox *bbox)
{
	int		j;
	t_coord	p;

	j = 0;
	while (1)
	{
		p = project_iso(data->map[row][j], 1, data->z_scale);
		update_bbox_values(p, bbox);
		if (data->map[row][j].z < bbox->min_z)
			bbox->min_z = data->map[row][j].z;
		if (data->map[row][j].z > bbox->max_z)
			bbox->max_z = data->map[row][j].z;
		if (data->map[row][j].end)
			break ;
		j++;
	}
}

static void	compute_bbox(t_data *data, t_bbox *bbox)
{
	int		i;

	bbox->min_x = INT_MAX;
	bbox->max_x = INT_MIN;
	bbox->min_y = INT_MAX;
	bbox->max_y = INT_MIN;
	bbox->min_z = INT_MAX;
	bbox->max_z = INT_MIN;
	i = 0;
	while (i < data->height)
	{
		process_bbox_row(data, i, bbox);
		i++;
	}
	bbox->z_range = bbox->max_z - bbox->min_z;
}

void	compute_scale(t_data *data)
{
	t_bbox	bbox;
	double	scale_x;
	double	scale_y;
	double	threshold;

	compute_bbox(data, &bbox);
	scale_x = (double)W_WIDTH / (bbox.max_x - bbox.min_x);
	scale_y = (double)W_HEIGHT / (bbox.max_y - bbox.min_y);
	threshold = (double)W_HEIGHT ;
	if (bbox.z_range > threshold)
		scale_y *= (threshold / bbox.z_range);
	if (scale_x < scale_y)
		data->scale = scale_x / 2;
	else
		data->scale = scale_y / 2;
}
