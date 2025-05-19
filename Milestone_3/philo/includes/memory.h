/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <okientzl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:28:20 by okientzl          #+#    #+#             */
/*   Updated: 2025/05/15 17:21:31 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stddef.h>

typedef struct s_mem_node
{
	void				*ptr;
	struct s_mem_node	*next;
}		t_mem_node;

void	*ft_xmalloc(size_t size);
void	mem_register(void *ptr);
void	mem_free_all(void);

#endif /* MEMORY_H */
