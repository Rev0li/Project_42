/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:25:30 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 12:15:27 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

static void	ft_sort_array(int *sorted_values, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (sorted_values[j] < sorted_values[min_index])
				min_index = j;
			j++;
		}
		tmp = sorted_values[i];
		sorted_values[i] = sorted_values[min_index];
		sorted_values[min_index] = tmp;
		i++;
	}
}

static int	*copy_stack_to_array(t_stack *stack, int size)
{
	int		*array;
	int		i;
	t_stack	*current;

	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	current = stack;
	i = 0;
	while (current)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
}

static void	assign_sorted_indices(t_stack *stack, int *sorted_values, int size)
{
	int		i;
	t_stack	*current;

	current = stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted_values[i])
			{
				current->f_index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	assign_index(t_stack *stack, int size)
{
	int	*sorted_values;

	sorted_values = copy_stack_to_array(stack, size);
	if (!sorted_values)
		return ;
	ft_sort_array(sorted_values, size);
	assign_sorted_indices(stack, sorted_values, size);
	free(sorted_values);
}
