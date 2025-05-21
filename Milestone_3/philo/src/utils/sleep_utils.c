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
#include "../../includes/mutex_utils.h"
#include <unistd.h>

void	smart_sleep(long duration_ms, t_data *data)
{
	long	start;

	start = ft_get_time_in_ms();
	while (1)
	{
		lock_mutex(&data->sim_lock);
		if (data->stop_simulation)
		{
			unlock_mutex(&data->sim_lock);
			break;
		}
		unlock_mutex(&data->sim_lock);

		if (ft_get_time_in_ms() - start >= duration_ms)
			break;
		usleep(250);
	}
}

