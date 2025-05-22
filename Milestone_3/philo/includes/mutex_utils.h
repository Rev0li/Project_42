/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:01:11 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/22 12:01:11 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MUTEX_UTILS_H
# define MUTEX_UTILS_H

# include <pthread.h>
# include "philo.h"

int	lock_mutex(pthread_mutex_t *mutex);
int	unlock_mutex(pthread_mutex_t *mutex);

int	lock_fork(t_philosopher *philo, int side);
int	unlock_fork(t_philosopher *philo, int side);

int	lock_print(t_data *data);
int	unlock_print(t_data *data);

#endif
