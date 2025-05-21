/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:27:36 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/19 09:42:47 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t meal_lock;
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
	int				stop_simulation;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	sim_lock;
	t_philosopher	*philos;
}		t_data;

/***** PHILO *****/
int		start_simulation(t_data *data);
void	*philosopher_routine(void *arg);
void	*supervisor(void *arg);
void	philo_print(t_philosopher *philo, const char *msg);

/***** UTILS *****/
int		ft_atoi(const char *str);
int		ft_safe_atoi(const char *str, int *dest);
long	ft_get_time_in_ms(void);
void	cleanup_simulation(t_data *data);
void	smart_sleep(long duration_ms, t_data *data);
int		exit_clean(char *msg, bool do_clean_simu, t_data *data);

#endif
