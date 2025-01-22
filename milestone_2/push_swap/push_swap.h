/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:35:23 by okientzl          #+#    #+#             */
/*   Updated: 2025/01/21 19:32:30 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*****  define NAME  *****/
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/***** includes *****/
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

/*****  struct  *****/
typedef struct s_stack
{
	int				value;
	int				f_index;
	int				mv_a;
	int				mv_b;
	int				a_up_or_down;
	int				b_up_or_down;
	struct s_stack	*next;

}	t_stack;

/*****  prototype  *****/

/*** algo ***/
void	sort_stack(int size, t_stack **a, t_stack **b);
void	assign_index(t_stack *stack, int size);
void	small_sort(t_stack **a, t_stack **b);
void	exec_mv(t_stack **a, t_stack **b, int index);

/*** tools ***/
int		best_index_to_mv(t_stack **a);
void	sort_a(t_stack **a);
void	sort_b(t_stack **b);
void	assign_mv_a(t_stack **a);
void	assign_mv_b(t_stack **a, t_stack **b);

/***  utils.c ***/
int		check_init(int argc, char **argv, t_stack **a);
int		display_error(void);
int		is_sorted(t_stack *a);
void	free_stack(t_stack **stack);
char	**free_arg(char **result, int i);
char	**ft_split(char const *s, char c, int *nb_arg);
int		ft_atoi(const char *str);
int		count_words(char const *s, char c);
char	**fill_tab(int argc, char **argv);
int		check_arg(int argc, char **argv);
/* lst */
int		init_stack(int nb_arg, char **tab_arg, t_stack **a);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstmin(t_stack *stack);
t_stack	*ft_lstmax(t_stack *stack);

/*** operation ***/
/* push */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
/* swaps */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
/* rotate */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
/* reverse_rotate */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
