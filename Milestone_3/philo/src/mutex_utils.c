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
#include <stdio.h>

int	lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
	{
		printf("Error: mutex lock failed\n");
		return (1);
	}
	return (0);
}

int	unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex))
	{
		printf("Error: mutex unlock failed\n");
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

int	lock_print(t_data *data)
{
	return (lock_mutex(&data->print_lock));
}

int	unlock_print(t_data *data)
{
	return (unlock_mutex(&data->print_lock));
}

