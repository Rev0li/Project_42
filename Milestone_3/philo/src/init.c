/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:40:18 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 12:40:18 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"
#include "../includes/memory.h"

int	init_simulation(t_data *data)
{
	int	i;

	data->forks = ft_xmalloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	data->philos = ft_xmalloc(sizeof(t_philosopher) * data->nbr_philo);
	pthread_mutex_init(&data->print_lock, NULL);

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].data = data;
		data->philos[i].last_meal = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nbr_philo];
		i++;
	}
	return (0);
}
