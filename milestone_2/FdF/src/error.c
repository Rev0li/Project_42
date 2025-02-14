/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:26:17 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/13 17:43:26 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"
/*#include "../include/color.h"*/

void	ft_show_error(t_data *data)
{
	if (data->error_code == 2 && !data->error_message)
		data->error_message = "Can't open MAP_FILE";
	else if (data->error_code == 3)
		data->error_message = "Error during MAP Reading";
	else if (data->error_code == 4)
		data->error_message = "Incorrect MAP_FILE";
	else if (data->error_code == 5)
		data->error_message = "MAP: Reading error on a point";
	else if (data->error_code == 7)
		data->error_message = "MLX init error";
	else if (data->error_code == 8)
		data->error_message = "Usage: ./fdf MAP_FILE";
	ft_print_error(data->error_message, data->error_code);
}

void	ft_print_error(char *error_message, int code)
{
	if (code < 3)
	{
		ft_putstr_fd("FDF: ", STDERR_FILENO);
		if (code == 2)
			ft_putstr_fd("File - ", STDERR_FILENO);
		ft_putstr_fd(error_message, STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("FDF: ", STDERR_FILENO);
		ft_putstr_fd(error_message, STDERR_FILENO);
	}
}
