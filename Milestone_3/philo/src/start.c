/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 06:01:19 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/21 06:01:23 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/time.h>
#include "../includes/philo.h"
#include "../includes/mutex_utils.h"

static int	wait_threads(t_data *data, pthread_t supervisor_thread)
{
	int	i;

	pthread_join(supervisor_thread, NULL);
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (0);
}

int	solo_philo(t_data *data)
{
	data->start_time = ft_get_time_in_ms();
	philo_print(&data->philos[0], "has taken a fork");
	smart_sleep(data->t_to_die, data);
	philo_print(&data->philos[0], "died");

	lock_mutex(&data->sim_lock);
	data->stop_simulation = 1;
	unlock_mutex(&data->sim_lock);

	return (0);
}

int	start_simulation(t_data *data)
{
	pthread_t	supervisor_thread;
	int			i;

	data->start_time = ft_get_time_in_ms();
	if (data->nbr_philo == 1)
		return (solo_philo(data));

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

	return (wait_threads(data, supervisor_thread));
}

