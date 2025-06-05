/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 06:00:59 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/22 14:01:38 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

static int	check_philo_dead(t_data *data, int i)
{
	long	time_now;
	long	time_last;

	time_now = ft_get_time_in_ms();
	lock_mutex(&data->philos[i].meal_lock);
	time_last = data->philos[i].last_meal;
	unlock_mutex(&data->philos[i].meal_lock);
	lock_mutex(&data->sim_lock);
	if (!data->stop_simulation && (time_now - time_last >= data->t_to_die))
	{
		lock_mutex(&data->print_lock);
		printf("%ld %d died\n", time_now - data->start_time,
			data->philos[i].id);
		unlock_mutex(&data->print_lock);
		data->stop_simulation = 1;
		unlock_mutex(&data->sim_lock);
		return (1);
	}
	unlock_mutex(&data->sim_lock);
	return (0);
}

static int	all_philos_ate_enough(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->nbr_philo)
	{
		lock_mutex(&data->philos[j].meal_lock);
		if (data->philos[j].has_finished == 0)
		{
			unlock_mutex(&data->philos[j].meal_lock);
			return (0);
		}
		unlock_mutex(&data->philos[j].meal_lock);
		j++;
	}
	lock_mutex(&data->sim_lock);
	data->stop_simulation = 1;
	unlock_mutex(&data->sim_lock);
	return (1);
}

void	*supervisor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			if (check_philo_dead(data, i))
				return (NULL);
			i++;
		}
		if (data->meals_required != -1 && all_philos_ate_enough(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
