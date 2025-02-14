/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:17:23 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/13 18:08:42 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

int	openfile(char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		data->error_message = strerror(errno);
		data->error_code = 2;
		return (-1);
	}
	data->file_name = filename;
	return (fd);
}

void	make_title(t_data *data)
{
	char	*title;

	title = ft_strjoin("FDF : ", data->file_name);
	data->title = title;
}
