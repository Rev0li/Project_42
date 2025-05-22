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
#include "../includes/mutex_utils.h"
#include <unistd.h>

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

// side: 0 = left, 1 = right
int	lock_fork(t_philosopher *philo, int side)
{
	if (side == 0)
		return (lock_mutex(philo->left_fork));
	else
		return (lock_mutex(philo->right_fork));
}

int	unlock_fork(t_philosopher *philo, int side)
{
	if (side == 0)
		return (unlock_mutex(philo->left_fork));
	else
		return (unlock_mutex(philo->right_fork));
}
