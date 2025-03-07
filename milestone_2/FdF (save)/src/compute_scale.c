/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:31:52 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/07 10:50:52 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"
#include <limits.h>

static void	update_bbox_values(t_coord p, int *min_x, int *max_x, int *min_y, int *max_y)
{
	if (p.x < *min_x)
		*min_x = p.x;
	if (p.x > *max_x)
		*max_x = p.x;
	if (p.y < *min_y)
		*min_y = p.y;
	if (p.y > *max_y)
		*max_y = p.y;
}

void	compute_bbox(t_data *data, int *min_x, int *max_x, int *min_y, int *max_y)
{
	int		i;
	int		j;
	t_coord	p;

	*min_x = INT_MAX;
	*max_x = INT_MIN;
	*min_y = INT_MAX;
	*max_y = INT_MIN;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (1)
		{
			p = project_iso(data->map[i][j], 1);
			update_bbox_values(p, min_x, max_x, min_y, max_y);
			if (data->map[i][j].end)
				break ;
			j++;
		}
		i++;
	}
}

int	compute_scale(t_data *data)
{
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
	double	scale_x;
	double	scale_y;
	double	scale;

	compute_bbox(data, &min_x, &max_x, &min_y, &max_y);
	if ((max_x - min_x) == 0 || (max_y - min_y) == 0)
		return (1);
	scale_x = (double)W_WIDTH / (double)(max_x - min_x);
	scale_y = (double)W_HEIGHT / (double)(max_y - min_y);
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	if (scale < 1.0)
		return (1);
	return ((int)scale);
}
