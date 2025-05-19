/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:27:36 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 12:44:13 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal;
	int				meals_eaten;
	struct s_data	*data;
}		t_philosopher;

typedef struct s_data
{
	int				nbr_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				meals_required;
	int				someone_died;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	t_philosopher	*philos;
}		t_data;

/***** PHILO *****/
int	init_simulation(t_data *data);
int	start_simulation(t_data *data);

/***** UTILS *****/
int		ft_atoi(const char *str);
int		ft_safe_atoi(const char *str, int *dest);
#endif
