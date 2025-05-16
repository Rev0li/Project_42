/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:08:21 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 14:26:15 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/checker_bonus.h"

int	exec_same_mv(char *line, t_stack **a, t_stack **b)
{
	if ((ft_strcmp(line, "pa\n")) == 0)
		return (pa_b(a, b), 0);
	else if ((ft_strcmp(line, "pb\n")) == 0)
		return (pb_b(a, b), 0);
	else if ((ft_strcmp(line, "sa\n")) == 0)
		return (sa_b(a), 0);
	else if ((ft_strcmp(line, "sb\n")) == 0)
		return (sb_b(b), 0);
	else if ((ft_strcmp(line, "ss\n")) == 0)
		return (ss_b(a, b), 0);
	else if ((ft_strcmp(line, "ra\n")) == 0)
		return (ra_b(a), 0);
	else if ((ft_strcmp(line, "rb\n")) == 0)
		return (rb_b(b), 0);
	else if ((ft_strcmp(line, "rr\n")) == 0)
		return (rr_b(a, b), 0);
	else if ((ft_strcmp(line, "rra\n")) == 0)
		return (rra_b(a), 0);
	else if ((ft_strcmp(line, "rrb\n")) == 0)
		return (rrb_b(b), 0);
	else if ((ft_strcmp(line, "rrr\n")) == 0)
		return (rrr_b(a, b), 0);
	else
		return (1);
}

int	copy_mv(t_stack **a, t_stack **b)
{
	char	**line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (line != NULL)
		{
			if (exec_same_mv(line, a, b))
			{
				free(line);
				return (1);
			}
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
