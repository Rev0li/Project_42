/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:57:43 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/13 20:03:05 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

bool	assign_color(char *token, t_coord *cell)
{
	char	**split_token;

	split_token = ft_split(token, ',');
	if (!split_token)
		return (false);
	if (split_token[0])
	{
		if (!is_integer(split_token[0]))
			return (false);
		cell->z = ft_atoi(split_token[0]);
	}
	if (split_token[1])
		cell->color = ft_hextoint(split_token[1]);
	else
		cell->color = 0xFFFFFF;
	free_token(split_token);
	return (true);
}

t_coord	fill_cell(char *token, int x, int y, bool *ok)
{
	t_coord	cell;

	cell = (t_coord){0};
	cell.x = x;
	cell.y = y;
	if (ft_strchr(token, ','))
	{
		if (!assign_color(token, &cell))
		{
			*ok = false;
			return (cell);
		}
	}
	else
	{
		if (!is_integer(token))
		{
			*ok = false;
			return (cell);
		}
		cell.z = ft_atoi(token);
		cell.color = 0xFFFFFF;
	}
	*ok = true;
	return (cell);
}

char	**alloc_width(char **token, int height, t_data *data, char *line)
{
	int		col_count;

	token = ft_split(line, ' ');
	if (!token)
		return (false);
	col_count = 0;
	while (token[col_count] && token[col_count][0] != '\n')
		col_count++;
	if (col_count < data->min_width)
		data->min_width = col_count;
	data->map[height] = malloc(sizeof(t_coord) * col_count);
	if (!data->map[height])
	{
		free_token(token);
		return (NULL);
	}
	return (token);
}

bool	fill_x(char *line, t_data *data, int height)
{
	char	**token;
	int		i;
	bool	ok;
	t_coord	cell;

	token = NULL;
	token = alloc_width(token, height, data, line);
	if (!token)
		return (false);
	i = 0;
	while (token[i] && token[i][0] != '\n')
	{
		cell = fill_cell(token[i], i, height, &ok);
		if (!ok)
		{
			free_height_map(data, height);
			free_token(token);
			return (false);
		}
		data->map[height][i] = cell;
		i++;
	}
	data->map[height][i - 1].end = true;
	free_token(token);
	return (true);
}

bool	fill_map(t_data *data)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(data->fd);
	if (!line)
	{
		data->error_code = 10;
		return (false);
	}
	while (line != NULL)
	{
		data->map = ft_realloc (data->map, sizeof(t_coord *) * height,
				sizeof(t_coord*) * (height + 1));
		if (!fill_x(line, data, height))
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(data->fd);
		height ++;
		data->height = height;
	}
	return (true);
}
