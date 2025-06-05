/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 06:01:19 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/22 13:04:18 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

static int	wait_threads(t_data *data, pthread_t supervisor_thread)
{
	pthread_join(supervisor_thread, NULL);
	while (data->nbr_thread_create < 0)
	{
		pthread_join(data->philos[data->nbr_thread_create].thread, NULL);
		data->nbr_thread_create--;
	}
	return (0);
}

static int	solo_philo(t_data *data)
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

	data->start_time = ft_get_time_in_ms();
	if (data->nbr_philo == 1)
		return (solo_philo(data));
	data->nbr_thread_create = 0;
	while (data->nbr_thread_create < data->nbr_philo)
	{
		data->philos[data->nbr_thread_create].last_meal = data->start_time;
		if (pthread_create(&data->philos[data->nbr_thread_create].thread, NULL,
				philosopher_routine, &data->philos[data->nbr_thread_create]))
			return (1);
		data->nbr_thread_create++;
	}
	if (pthread_create(&supervisor_thread, NULL, supervisor, data))
		return (1);
	return (wait_threads(data, supervisor_thread));
}
