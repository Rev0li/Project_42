/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:39:24 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/19 11:22:28 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"
#include "../includes/mutex_utils.h"
#include <unistd.h>

void	*supervisor(void *arg)
{
	t_data	*data = (t_data *)arg;
	int		i;

	while (1)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			lock_mutex(&data->print_lock);
			if (!data->someone_died &&
				(ft_get_time_in_ms() - data->philos[i].last_meal >= data->t_to_die))
			{
				data->someone_died = 1;
				printf("%ld %d died\n",
		   ft_get_time_in_ms() - data->start_time,
		   data->philos[i].id);
				unlock_mutex(&data->print_lock);
				return (NULL);
			}
			unlock_mutex(&data->print_lock);
			i++;
		}

		if (!data->someone_died && data->meals_required != -1)
		{
			int	full = 0;
			int	j = 0;
			while (j < data->nbr_philo)
			{
				lock_mutex(&data->print_lock);
				if (data->philos[j].meals_eaten >= data->meals_required)
					full++;
				unlock_mutex(&data->print_lock);
				j++;
			}
			if (full == data->nbr_philo)
			{
				data->someone_died = 1;
				return (NULL);
			}
		}
		usleep(1000);
}
	return (NULL);
}

void	philo_print(t_philosopher *philo, const char *msg)
{
	lock_print(philo->data);
	printf("%ld %d %s\n",
		ft_get_time_in_ms() - philo->data->start_time,
		philo->id,
		msg);

	unlock_print(philo->data);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher *philo = (t_philosopher *)arg;

	if (philo->id % 2 == 0) // petit décalage pour éviter tous les locks simultanés
		smart_sleep(philo->data->t_to_eat, philo->data);

	while (1)
	{
		if (philo->data->someone_died)
			break;
		philo_print(philo, "is thinking");

		// 🥄 Prendre les fourchettes
		lock_fork(philo, 0);
		philo_print(philo, "has taken a fork");

		lock_fork(philo, 1);
		philo_print(philo, "has taken a fork");

		// 🍝 Manger
		philo_print(philo, "is eating");
		lock_mutex(&philo->data->print_lock);
		philo->last_meal = ft_get_time_in_ms();
		philo->meals_eaten++;

		unlock_mutex(&philo->data->print_lock);
		smart_sleep(philo->data->t_to_eat, philo->data);

		// 🧼 Reposer les fourchettes
		unlock_fork(philo, 1);
		unlock_fork(philo, 0);

		// 😴 Dormir
		philo_print(philo, "is sleeping");
		smart_sleep(philo->data->t_to_sleep, philo->data);
	}
	return (NULL);
}

