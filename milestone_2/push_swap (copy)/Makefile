# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okientzl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 07:26:30 by okientzl          #+#    #+#              #
#    Updated: 2024/12/16 20:16:00 by okientzl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of final execut
NAME = push_swap

# Files sources
SRCS = push_swap.c \
	   operation/swaps.c \
       utils/ft_atoi.c \
       utils/checker.c \
	   utils/lst.c

# Header
HEADER = push_swap.h

# Files obj (.o generates after comp .c)
OBJ = $(SRCS:.c=.o)

# Comp
CC = cc

# Flags of compilation
CFLAGS = -Wall -Wextra -Werror

# (Default)
all: $(NAME)

# Compilation of execut
$(NAME): $(OBJ)
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

