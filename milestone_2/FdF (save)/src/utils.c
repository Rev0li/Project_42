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
	int len;

	len = 0;
	while (!row[len].end)
		len++;
	return (len + 1);
}

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
