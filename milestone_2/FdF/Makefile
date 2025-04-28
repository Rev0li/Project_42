# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okientzl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 09:05:51 by okientzl          #+#    #+#              #
#    Updated: 2025/03/12 16:51:02 by okientzl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -MMD -MP -Iinclude -Ofast

MLX_DIR=./lib/minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_LIB = $(MLX_DIR)/libmlx.a

LIB_DIR = lib/ult_lib
LIB = $(LIB_DIR)/ult_lib.a

# Files sources
SRCS =	src/fdf.c				\
		src/draw.c				\
		src/tools_draw.c		\
		src/compute_scale.c		\
		src/utils.c				\
		src/valid_map_file.c	\
		src/fill_map.c			\
		src/ft_free.c			\
		src/error.c

HEADER = include/fdf.h 

# Directory for obj and dep
OBJDIR = obj
DEPDIR = dep

OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEPS = $(SRCS:src/%.c=$(DEPDIR)/%.d)

all: lib_update $(NAME)

# Compilation of lib
lib_update:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR)

# Create necessary directories
$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

### --- Compilation rules --- ###

# Compilation of the main executable
$(NAME): $(OBJS) $(LIB) $(MLX_LIB) | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(MLX_LIB) $(MLX_FLAGS)

# Rule of compilation for main exec src 
$(OBJDIR)/%.o: src/%.c Makefile $(HEADER) | $(OBJDIR) $(DEPDIR)
	@mkdir -p $(dir $@) $(DEPDIR)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@ -MF $(DEPDIR)/$(basename $(notdir $<)).d

# Clean : delete folder obj
clean:
	rm -rf $(OBJDIR) $(DEPDIR)
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

# Fclean : delete exec and clean
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

# Recompile everything from scratch
re: fclean all

# Include file of dep
-include $(DEPS)

.PHONY: all clean fclean re lib_update
