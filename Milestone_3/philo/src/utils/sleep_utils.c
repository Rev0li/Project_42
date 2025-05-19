/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:31 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/19 11:12:31 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/philo.h"
#include <unistd.h>

void	smart_sleep(long duration_ms, t_data *data)
{
	long	start;

	start = ft_get_time_in_ms();
	while (!data->someone_died)
	{
		if (ft_get_time_in_ms() - start >= duration_ms)
			break;
		usleep(250); // micro-sommeil pour ne pas bloquer le CPU
	}
}

