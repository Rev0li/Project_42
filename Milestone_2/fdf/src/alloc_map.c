/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:00:10 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/14 12:38:54 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

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

bool	alloc_height(t_data *data, int height)
{
	data->map = ft_realloc (data->map, sizeof(t_coord *) * height,
			sizeof(t_coord*) * (height + 1));
	if (!data->map)
		return (false);
	return (true);
}
