/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:26:51 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/22 13:55:12 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

static t_data	*safe_memory(int nbr_philo)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->forks = malloc(sizeof(t_fork) * nbr_philo);
	if (!data->forks)
	{
		free(data);
		return (NULL);
	}
	data->philos = malloc(sizeof(t_philosopher) * nbr_philo);
	if (!data->philos)
	{
		free(data->forks);
		free(data);
		return (NULL);
	}
	return (data);
}

static int	parse_args(t_data *data, int argc, char **argv)
{
	data->nbr_mutex_init = 0;
	data->stop_simulation = 0;
	data->start_time = 0;
	data->meals_required = -1;
	if (ft_safe_atoi(argv[1], &data->nbr_philo)
		|| ft_safe_atoi(argv[2], &data->t_to_die)
		|| ft_safe_atoi(argv[3], &data->t_to_eat)
		|| ft_safe_atoi(argv[4], &data->t_to_sleep)
		|| (argc == 6 && ft_safe_atoi(argv[5], &data->meals_required)))
		return (1);
	if (data->nbr_philo < 1
		|| data->t_to_die < 1
		|| data->t_to_eat < 1
		|| data->t_to_sleep < 1
		|| (argc == 6 && data->meals_required < 1))
		return (1);
	return (0);
}

static void	assign_philosopher(t_data *data, int i)
{
	data->philos[i].id = i + 1;
	data->philos[i].meals_eaten = 0;
	data->philos[i].has_finished = 0;
	data->philos[i].data = data;
	data->philos[i].last_meal = ft_get_time_in_ms();
	data->philos[i].left_fork = &data->forks[i];
	data->philos[i].right_fork = &data->forks[(i + 1) % data->nbr_philo];
}
/*      [T1]             [T2]             [T3]*/
/*  Philosopher 1   Philosopher 2   Philosopher 3*/
/*     (ID: 1)          (ID: 2)         (ID: 3)*/
/*    /      \        /      \        /      \*/
/*  [F1]    [F2]    [F2]    [F3]    [F3]    [F1]*/
/*Mutex1  Mutex2  Mutex2  Mutex3  Mutex3  Mutex1*/

static int	init_simulation(t_data *data, t_mutex_node **mutex_list)
{
	int	i;

	if (safe_init_mutex(&data->print_lock, mutex_list)
		|| safe_init_mutex(&data->sim_lock, mutex_list))
	{
		destroy_mutex_list(*mutex_list);
		return (1);
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		data->forks[i].taken = false;
		if (safe_init_mutex(&data->forks[i].locker, mutex_list)
			|| safe_init_mutex(&data->philos[i].meal_lock, mutex_list))
		{
			destroy_mutex_list(*mutex_list);
			return (1);
		}
		assign_philosopher(data, i);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			*data;
	int				nbr_philo;
	t_mutex_node	*mutex_list;

	mutex_list = NULL;
	if (argc != 5 && argc != 6)
		return (destroy_and_free("invalid args", false, NULL, mutex_list));
	if (ft_safe_atoi(argv[1], &nbr_philo) || nbr_philo < 1)
		return (destroy_and_free("invalid nbr philo", false, NULL, mutex_list));
	data = safe_memory(nbr_philo);
	if (!data)
		return (destroy_and_free("Error malloc", false, data, mutex_list));
	if (parse_args(data, argc, argv))
		return (destroy_and_free("invalid args", false, data, mutex_list));
	if (init_simulation(data, &mutex_list))
		return (destroy_and_free("fail init simu", false, data, mutex_list));
	if (start_simulation(data))
		return (destroy_and_free("fail start simu", true, data, mutex_list));
	cleanup_simulation(data, data->nbr_philo);
	free_mutex_list(mutex_list);
	ft_free_all(data);
	return (0);
}
