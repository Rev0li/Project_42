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

static void	philo_take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		take_fork(philo->left_fork);
		philo_print(philo, "has taken a fork");
		take_fork(philo->right_fork);
		philo_print(philo, "has taken a fork");
	}
	else
	{
		take_fork(philo->right_fork);
		philo_print(philo, "has taken a fork");
		take_fork(philo->left_fork);
		philo_print(philo, "has taken a fork");
	}
}

static void	philo_eat(t_philosopher *philo)
{
	philo_print(philo, "is eating");
	lock_mutex(&philo->meal_lock);
	philo->meals_eaten++;
	if (philo->data->meals_required != -1
		&& philo->meals_eaten == philo->data->meals_required)
		philo->has_finished = 1;
	philo->last_meal = ft_get_time_in_ms();
	unlock_mutex(&philo->meal_lock);
	smart_sleep(philo->data->t_to_eat, philo->data);
	philo->is_thinking = false;
}

static void	philo_sleep(t_philosopher *philo)
{
	philo_print(philo, "is sleeping");
	smart_sleep(philo->data->t_to_sleep, philo->data);
	if (philo->data->nbr_philo % 2 != 0)
		usleep(500);
	philo->is_thinking = false;
}

static void	philo_think(t_philosopher *philo)
{
	if (philo->is_thinking == false)
	{
		philo_print(philo, "is thinking");
		philo->is_thinking = true;
	}
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	philo->is_thinking = false;
	if (philo->id % 2 == 0)
	{
		philo_think(philo);
		smart_sleep(philo->data->t_to_eat / 2, philo->data);
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
		philo_put_forks(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
