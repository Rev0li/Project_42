/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 06:01:26 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/22 13:56:07 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"
#include "../includes/mutex_utils.h"

void	philo_print(t_philosopher *philo, const char *msg)
{
	lock_mutex(&philo->data->sim_lock);
	if (!philo->data->stop_simulation)
	{
		unlock_mutex(&philo->data->sim_lock);
		lock_mutex(&philo->data->print_lock);
		printf("%ld %d %s\n",
			ft_get_time_in_ms() - philo->data->start_time,
			philo->id, msg);
		unlock_mutex(&philo->data->print_lock);
	}
	else
		unlock_mutex(&philo->data->sim_lock);
}

static void	philo_take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		lock_fork(philo, 0);
		philo_print(philo, "has taken a fork");
		lock_fork(philo, 1);
		philo_print(philo, "has taken a fork");
	}
	else
	{
		lock_fork(philo, 1);
		philo_print(philo, "has taken a fork");
		lock_fork(philo, 0);
		philo_print(philo, "has taken a fork");
	}
}

static void	philo_eat(t_philosopher *philo)
{
	philo_print(philo, "is eating");
	lock_mutex(&philo->meal_lock);
	philo->last_meal = ft_get_time_in_ms();
	philo->meals_eaten++;
	if (philo->data->meals_required != -1
		&& philo->meals_eaten == philo->data->meals_required)
		philo->has_finished = 1;
	unlock_mutex(&philo->meal_lock);
	smart_sleep(philo->data->t_to_eat, philo->data);
	unlock_fork(philo, 1);
	unlock_fork(philo, 0);
}

static void	philo_sleep(t_philosopher *philo)
{
	philo_print(philo, "is sleeping");
	smart_sleep(philo->data->t_to_sleep, philo->data);
}
static void	philo_think(t_philosopher *philo)
{
	philo_print(philo, "is thinking");
	if (philo->id % 2 == 0)
		smart_sleep(philo->data->t_to_eat, philo->data);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
	{
		philo_print(philo, "is thinking");
		smart_sleep(philo->data->t_to_eat, philo->data);
	}
	while (1)
	{
		lock_mutex(&philo->data->sim_lock);
		if (philo->data->stop_simulation)
		{
			unlock_mutex(&philo->data->sim_lock);
			break ;
		}
		unlock_mutex(&philo->data->sim_lock);
		philo_think(philo);
		philo_take_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
