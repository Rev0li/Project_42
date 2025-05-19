/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:26:51 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/16 12:38:08 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"
#include "../includes/memory.h"

int	parse_args(t_data *data, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
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
	data->someone_died = 0;
	data->start_time = 0;
	return (0);
}


int	main(int argc, char **argv)
{
	t_data *data;

	data = ft_xmalloc(sizeof(t_data));
	if (parse_args(data, argc, argv))
	{
		printf("Error: invalid arguments\n");
		mem_free_all();
		return (1);
	}
	if (init_simulation(data))
	{
		printf("Error: failed to init simulation");
		mem_free_all();
		return (1);
	}

	mem_free_all();
	return (0);
}
