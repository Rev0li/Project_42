/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:03:10 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/06 14:16:19 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*****  define NAME  *****/
#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include "push_swap.h"

/***  GNL  ***/
char	*ft_free(char **str);
char	*polish(char *storage);
char	*get_current_line(char *storage);
char	*create_buf(char *storage, int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);

/***  checker ***/
int		exec_same_mv(char *line, t_stack **a, t_stack **b);
int		copy_mv(t_stack **a, t_stack **b);

/*** operation ***/
/* push */
void	pa_b(t_stack **a, t_stack **b);
void	pb_b(t_stack **a, t_stack **b);
/* swaps */
void	sa_b(t_stack **a);
void	sb_b(t_stack **b);
void	ss_b(t_stack **a, t_stack **b);
/* rotate */
void	ra_b(t_stack **a);
void	rb_b(t_stack **b);
void	rr_b(t_stack **a, t_stack **b);
/* reverse_rotate */
void	rra_b(t_stack **a);
void	rrb_b(t_stack **b);
void	rrr_b(t_stack **a, t_stack **b);

#endif
