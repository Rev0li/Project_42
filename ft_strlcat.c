/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:19:10 by okientzl          #+#    #+#             */
/*   Updated: 2024/11/08 12:25:55 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t dst_len = 0;
    size_t src_len = 0;
    size_t i = 0;

    // Calculate lengths of dst and src
    while (dst[dst_len] != '\0' && dst_len < size)
        dst_len++;
    while (src[src_len] != '\0')
        src_len++;

    // If size is 0 or less than dst_len, return size + src_len (no concatenation occurs)
    if (size <= dst_len)
        return size + src_len;

    // Append src to dst within size constraints
    while (src[i] != '\0' && dst_len + i < size - 1)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    // Null-terminate dst
    if (dst_len + i < size)
        dst[dst_len + i] = '\0';

    return dst_len + src_len;
}


