/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:35:23 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/20 16:32:13 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*****  define NAME  *****/
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*****  include  *****/
# include <stdlib.h>
# include <stdio.h>
/*****  struct  *****/
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;

} t_stack;

/*****  prototype  *****/

/*** checker.c ***/
int check_arg(int argc, char **argv);
int display_error(void);

/***  utils.c ***/
int 	ft_atoi(const char *str);
/* lst */
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstiter(t_stack *lst);

/*** operation ***/
void sa(t_stack **a);
void sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif
