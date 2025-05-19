/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:44:37 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/19 11:22:09 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/time.h>
#include "../includes/philo.h"

int	start_simulation(t_data *data)
{
	pthread_t supervisor_thread;

	int	i;

	data->start_time = ft_get_time_in_ms();
	if (data->nbr_philo == 1)
	{
		data->start_time = ft_get_time_in_ms();
		philo_print(&data->philos[0], "has taken a fork");
		smart_sleep(data->t_to_die, data);
		philo_print(&data->philos[0], "died");
		data->someone_died = 1;
		return (0);
	}

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philos[i].last_meal = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL,
					 philosopher_routine, &data->philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&supervisor_thread, NULL, supervisor, data))
		return (1);
	pthread_join(supervisor_thread, NULL);

	return (0);
}

