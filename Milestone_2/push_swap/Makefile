# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okientzl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 07:26:30 by okientzl          #+#    #+#              #
#    Updated: 2025/02/06 14:40:44 by okientzl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Name of final executables
NAME = push_swap
NAME_BONUS = checker

# Source for main exec
SRCS =	src/push_swap.c					\
		src/algo/add_index.c			\
		src/algo/assign_mv.c			\
		src/algo/best_index_to_mv.c		\
		src/algo/exec_move.c			\
		src/algo/rest_sort.c			\
		src/algo/sort_stack.c			\
		src/algo/tools.c				\
		src/utils/check_init.c			\
		src/utils/display_error.c		\
		src/utils/ft_atoi.c				\
		src/utils/ft_init_list.c		\
		src/utils/is_function.c			\
		src/utils/lst_utils.c			\
		src/operation/push.c			\
		src/operation/reverse_rotate.c	\
		src/operation/rotate.c			\
		src/operation/swaps.c

# Header for main exec
HEADER = include/push_swap.h

# Source for bonus
SRCS_BONUS =	src_bonus/checker_bonus.c				\
				src_bonus/get_next_line_bonus.c			\
				src_bonus/get_next_line_utils_bonus.c	\
				src_bonus/push_bonus.c					\
				src_bonus/reverse_rotate_bonus.c		\
				src_bonus/rotate_bonus.c				\
				src_bonus/swaps_bonus.c					\
				src_bonus/utils_bonus.c

# Header for bonus exec
HEADER_BONUS = include/checker_bonus.h

# Directory for obj and dep
OBJDIR = obj

# Files obj and dep
OBJ = $(SRCS:src/%.c=$(OBJDIR)/%.o)
OBJ_BONUS = $(SRCS_BONUS:src_bonus/%.c=$(OBJDIR)/%.o)

# Catch main for not bug bonus
OBJ_LIB = $(filter-out $(OBJDIR)/push_swap.o, $(OBJ))

DEP = $(OBJ:.o=.d)
DEP_BONUS = $(OBJ_BONUS:.o=.d)

# Comp flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP

all: $(NAME)

$(OBJDIR):
	@mkdir -p $@

# Compilation of main exec
$(NAME): $(OBJ) | $(OBJDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Rule of compilation for main exec src 
$(OBJDIR)/%.o: src/%.c Makefile $(HEADER) | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

# Compilation of bonus exec
$(NAME_BONUS): $(OBJ_BONUS) $(OBJ_LIB) | $(OBJDIR)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(OBJ_LIB)

# Rule of compilation for bonus exec src
$(OBJDIR)/%.o: src_bonus/%.c $(HEADER_BONUS) | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean : delete folder obj
clean:
	rm -rf $(OBJDIR)

# Fclean : delete exec and clean
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

# Compilation again : fclean to all
re: fclean all

# Include file of dep
-include $(DEP) $(DEP_BONUS)

.PHONY: all clean fclean re bonus

