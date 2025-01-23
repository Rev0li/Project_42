# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okientzl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 09:05:51 by okientzl          #+#    #+#              #
#    Updated: 2025/01/23 11:11:57 by okientzl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Name of final execut
NAME = fdf 

# Files sources
SRCS =	src/fdf.c				\
		ult_lib/ult_lib.a	


# Header
HEADER = src/fdf.h

# Files obj (.o generates after comp .c)
OBJ = $(SRCS:.c=.o)

# Comp
CC = cc

# Flags of compilation
CFLAGS = -Wall -Wextra -Werror -g3 

# (Default)
all: $(NAME)

# Compilation of execut
$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# Compilation of files .c to .o
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

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

# -Imlx
