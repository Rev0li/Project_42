/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:49:37 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/06 09:03:04 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

bool	is_valid_extension(const char *filename)
{
	const char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (false);
	return (ft_strcmp(ext, ".fdf") == 0);
}

bool	valid_map_file(t_data *data)
{
	if (!is_valid_extension(data->file_name))
	{
		data->error_code = 8;
		return (false);
	}
	if (!fill_map(data))
	{
		data->error_code = 11;
		return (false);
	}
	return (true);
}
