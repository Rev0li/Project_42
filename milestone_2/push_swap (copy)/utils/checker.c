/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:36:11 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/16 17:58:51 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include <unistd.h>
#include <limits.h>

int display_error(void)
{
    write(2, "Error\n", 6);
    return (1);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int is_valid_integer(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

static int has_duplicates(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_arg(int argc, char **argv)
{
    int i;

    if (argc < 2)
        return (1);

    i = 1;
    while (i < argc)
    {
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (1);
        if (!is_valid_integer(argv[i]))
            return (1);
        i++;
    }

    if (has_duplicates(argc, argv))
        return (1);

    return (0);
}
