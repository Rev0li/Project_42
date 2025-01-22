# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okientzl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 07:26:30 by okientzl          #+#    #+#              #
#    Updated: 2025/01/21 15:55:55 by okientzl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of final execut
NAME = push_swap

# Files sources
SRCS = push_swap.c					\
	   algo/add_index.c				\
	   algo/sort_stack.c			\
	   algo/tools.c					\
	   algo/rest_sort.c				\
	   algo/exec_move.c				\
	   algo/assign_mv.c				\
	   algo/best_index_to_mv.c		\
	   check_init/check_init.c		\
	   check_init/display_error.c	\
	   check_init/checker.c			\
	   utils/ft_init_list.c			\
	   utils/ft_split.c				\
	   utils/is_function.c			\
	   utils/ft_atoi.c				\
	   utils/fill_tab.c				\
	   utils/lst_utils.c			\
	   operation/push.c				\
	   operation/swaps.c			\
	   operation/rotate.c			\
	   operation/reverse_rotate.c

# Header
HEADER = push_swap.h

# Files obj (.o generates after comp .c)
OBJ = $(SRCS:.c=.o)

# Comp
CC = cc

# Flags of compilation
CFLAGS = -Wall -Wextra -Werror -g

# (Default)
all: $(NAME)

# Compilation of execut
$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Compilation of files .c to .o
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# clean files objs
clean:
	rm -f $(OBJ)

# with execu
fclean: clean
	rm -f $(NAME)

# against compil
re: fclean all

# declass this word
.PHONY: all clean fclean re

