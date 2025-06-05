/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:27:36 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/22 13:27:34 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <sys/time.h>

typedef struct s_fork
{
	bool				taken;
	pthread_mutex_t		locker;
}	t_fork;

typedef struct s_mutex_node
{
	pthread_mutex_t		*mutex;
	struct s_mutex_node	*next;
}	t_mutex_node;

typedef struct s_philosopher
{
	int					id;
	pthread_t			thread;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_mutex_t		meal_lock;
	long				last_meal;
	int					meals_eaten;
	int					has_finished;
	struct s_data		*data;
	bool				is_thinking;
}		t_philosopher;

typedef struct s_data
{
	int					nbr_philo;
	int					nbr_thread_create;
	int					nbr_mutex_init;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					meals_required;
	int					stop_simulation;
	long				start_time;
	t_fork				*forks;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		sim_lock;
	t_philosopher		*philos;
}		t_data;

/***** PHILO *****/
int		start_simulation(t_data *data);
void	*philosopher_routine(void *arg);
void	philo_print(t_philosopher *philo, const char *msg);
int		safe_init_mutex(pthread_mutex_t *mutex, t_mutex_node **list);

/***** SUPERVISOR *****/
void	*supervisor(void *arg);

/***** UTILS *****/
int		ft_safe_atoi(const char *str, int *dest);
long	ft_get_time_in_ms(void);
void	smart_sleep(long duration_ms, t_data *data);

/***** CLEANUP *****/
void	cleanup_simulation(t_data *data, int max);
void	ft_free_all(t_data *data);
void	destroy_mutex_list(t_mutex_node *list);
void	free_mutex_list(t_mutex_node *list);
int		destroy_and_free(char *msg, bool do_clean_simu,
			t_data *data, t_mutex_node *list);

/***** LOCK UNLOCK *****/
int		lock_mutex(pthread_mutex_t *mutex);
int		unlock_mutex(pthread_mutex_t *mutex);
int		lock_print(t_data *data);
int		unlock_print(t_data *data);

/***** FORK *****/
void	philo_put_forks(t_philosopher *philo);
void	take_fork(t_fork *fork);

#endif
