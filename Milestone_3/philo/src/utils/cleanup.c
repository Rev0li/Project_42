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

void	ft_free_all(t_data *data)
{
	if (data != NULL)
	{
		if (data->forks != NULL)
		{
			free(data->forks);
			data->forks = NULL;
		}
		if (data->philos != NULL)
		{
			free(data->philos);
			data->philos = NULL;
		}
		free(data);
		data = NULL;
	}
}

void	free_mutex_list(t_mutex_node *list)
{
	t_mutex_node	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	destroy_mutex_list(t_mutex_node *list)
{
	t_mutex_node	*tmp;

	while (list)
	{
		pthread_mutex_destroy(list->mutex);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	cleanup_simulation(t_data *data, int max)
{
	int	i;

	i = 0;
	if (data->nbr_philo != 1)
	{
		while (i < data->nbr_thread_create)
		{
			pthread_join(data->philos[i].thread, NULL);
			i++;
		}
	}
	i = 0;
	while (i < max)
	{
		pthread_mutex_destroy(&data->forks[i].locker);
		pthread_mutex_destroy(&data->philos[i].meal_lock);
		i++;
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->sim_lock);
}

int	destroy_and_free(char *msg, bool do_clean_simu,
	t_data *data, t_mutex_node *list)
{
	printf("%s\n", msg);
	if (do_clean_simu == true)
	{
		cleanup_simulation(data, data->nbr_thread_create);
		free_mutex_list(list);
	}
	ft_free_all(data);
	return (1);
}
