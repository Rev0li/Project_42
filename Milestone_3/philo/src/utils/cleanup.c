/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:08:59 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/19 11:08:59 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/philo.h"
#include "../../includes/memory.h"

void	cleanup_simulation(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].meal_lock);
		i++;
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->sim_lock);
}

int	exit_clean(char *msg, bool do_clean_simu, t_data *data)
{
	printf("%s\n",msg);
	if (do_clean_simu == true)
		cleanup_simulation(data);
	mem_free_all();
	return (1);
}
