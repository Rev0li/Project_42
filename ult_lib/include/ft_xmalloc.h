/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:28:20 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/13 19:28:23 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XMALLOC_H
# define FT_XMALLOC_H

# include <stddef.h>

typedef struct s_mem_node
{
	void				*ptr;
	struct s_mem_node	*next;
}		t_mem_node;

void	*ft_xmalloc(int size);
void	mem_register(void *ptr);
void	mem_free_all(void);

#endif /* FT_XMALLOC_H */
