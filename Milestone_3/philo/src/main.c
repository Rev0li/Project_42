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
#include "../includes/memory.h"

int	parse_args(t_data *data, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
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

int	init_simulation(t_data *data)
{
	int	i;

	data->forks = ft_xmalloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	data->philos = ft_xmalloc(sizeof(t_philosopher) * data->nbr_philo);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->sim_lock, NULL);
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philos[i].meal_lock, NULL);
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].has_finished = 0;
		data->philos[i].data = data;
		data->philos[i].last_meal = ft_get_time_in_ms();
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nbr_philo];
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_xmalloc(sizeof(t_data));
	if (parse_args(data, argc, argv))
		return (exit_clean("Error: invalid arguments", false, data));
	if (init_simulation(data))
		return (exit_clean("Error: failed to init simulation", false, data));
	if (start_simulation(data))
		return (exit_clean("Error: failed to start simulation", true, data));
	cleanup_simulation(data);
	mem_free_all();
	return (0);
}
