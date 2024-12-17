/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:35:23 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/16 19:56:37 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*****  define NAME  *****/
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*****  include  *****/

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
long 	ft_atoi(const char *str);
/* lst */
t_stack	*ft_lstnew(void *content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstiter(t_stack *lst, void (*f)(void *));

/*** operation ***/
void sa(t_stack **a);
void sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif
