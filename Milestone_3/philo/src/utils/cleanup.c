/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:08:59 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/22 12:02:54 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/philo.h"
#include "../../includes/mutex_utils.h"
#include "../../includes/memory.h"

void	cleanup_simulation(t_data *data, int max)
{
	int	i;

	i = 0;
	while (i < data->nbr_thread_create)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < max)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].meal_lock);
		i++;
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->sim_lock);
}

int	destroy_and_free(char *msg, bool do_clean_simu, t_data *data)
{
	lock_print(data);
	printf("%s\n", msg);
	unlock_print(data);
	if (do_clean_simu == true)
		cleanup_simulation(data, data->nbr_thread_create);
	mem_free_all();
	return (1);
}
