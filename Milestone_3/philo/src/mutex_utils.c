/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:31:47 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 12:32:04 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	safe_init_mutex(pthread_mutex_t *mutex, t_mutex_node **list)
{
	t_mutex_node	*new;

	if (pthread_mutex_init(mutex, NULL) != 0)
		return (1);
	new = malloc(sizeof(t_mutex_node));
	if (!new)
		return (1);
	new->mutex = mutex;
	new->next = *list;
	*list = new;
	return (0);
}

int	lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
	{
		write(2, "mutex_lock failed\n", 18);
		return (1);
	}
	return (0);
}

int	unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex))
	{
		write(2, "mutex_unlock failed\n", 20);
		return (1);
	}
	return (0);
}

void	take_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->locker);
	while (fork->taken)
	{
		pthread_mutex_unlock(&fork->locker);
		usleep(100);
		pthread_mutex_lock(&fork->locker);
	}
	fork->taken = true;
	pthread_mutex_unlock(&fork->locker);
}

void	philo_put_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->left_fork->locker);
	philo->left_fork->taken = false;
	pthread_mutex_unlock(&philo->left_fork->locker);
	pthread_mutex_lock(&philo->right_fork->locker);
	philo->right_fork->taken = false;
	pthread_mutex_unlock(&philo->right_fork->locker);
}
