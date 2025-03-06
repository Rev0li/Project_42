# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okientzl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 09:05:51 by okientzl          #+#    #+#              #
#    Updated: 2025/02/13 17:41:14 by okientzl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -MMD -MP -Iinclude

MLX_DIR=./lib/minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_LIB = $(MLX_DIR)/libmlx.a

LIB_DIR = lib/ult_lib
LIB = $(LIB_DIR)/ult_lib.a

# Files sources
SRCS =	src/fdf.c				\
		src/draw.c				\
		src/transform.c			\
		src/compute_scale.c		\
		src/utils.c				\
		src/valid_map_file.c	\
		src/fill_map.c			\
		src/ft_free.c			\
		src/debug.c 			\
		src/error.c

HEADER = include/fdf.h 

# Directory for obj and dep
OBJDIR = obj
OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEPS = $(OBJ:.o=.d)

all: lib_update $(NAME)

# Compilation of lib
lib_update:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR)



### --- Compilation rules --- ###

# Compilation of the main executable
$(NAME): $(OBJS) $(LIB) $(MLX_LIB) | $(OBJDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(MLX_LIB) $(MLX_FLAGS)

# Rule of compilation for main exec src 
$(OBJDIR)/%.o: src/%.c Makefile $(HEADER) | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@


### --- Classic rules --- ###
# Create obj directory
$(OBJDIR):
	@mkdir -p $@

# Clean : delete folder obj
clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

# Fclean : delete exec and clean
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean

# Recompile everything from scratch
re: fclean all

# Include file of dep
-include $(DEPS)

.PHONY: all clean fclean re lib_update
