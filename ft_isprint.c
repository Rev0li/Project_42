/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:17:48 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 12:17:50 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_isprint(int c)
{
    if (c >= ' ' && c <= '~')
        return 1;
    else
        return 0;
}

