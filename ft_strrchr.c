/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:15:04 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 14:22:09 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    const char *last_occurrence = NULL;
    while (*s)
    {
        if (*s == (char)c)
            last_occurrence = s;
        s++;
    }
    if (c == '\0') // Si le caractère recherché est '\0'
        return (char *)s;
    return (char *)last_occurrence;
}
